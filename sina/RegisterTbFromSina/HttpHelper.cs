/*
 类说明:本类代码在苏飞HttpHelper类的基础上有部分改写.
 修改人:cload
 联系QQ:309363537
 修改日期:2014-11-08
*/
#region [sufeinet]版权声明
/*
 类说明：HttpHelper类，用来实现Http访问，Post或者Get方式的，直接访问，带Cookie的，带证书的等方式，可以设置代理
 重要提示：请不要自行修改本类，如果因为你自己修改后将无法升级到新版本。如果确实有什么问题请到官方网站提建议，
 我们一定会及时修改
 编码日期：2011-09-20
 编 码 人：苏飞
 联系方式：361983679
 官方网址:http://www.sufeinet.com/thread-3-1-1.html
 修改日期：2013-09-29
 版 本 号：1.4.2
*/
#endregion

using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;
using System.Net;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography.X509Certificates;
using System.Net.Security;
namespace RegisterTbFromSina
{
    public class HttpHelper
    {
        #region 变量定义
        private Encoding encoding = null;
        private Encoding postencoding = Encoding.Default;
        private HttpWebRequest request = null;
        private HttpWebResponse response = null;
        private bool IsRedirect = false;    //存在重定向
        private string JumpCookies = "";//重定向过程中产生的Cookie
        string LastJumpUrl = "";
        #endregion

        #region 请求信息
        public HttpResult GetHtml(HttpItem item)
        {
            #region 参数设置
            IsRedirect = false;
            JumpCookies = "";
        Redirect:
            ;
            HttpResult result = new HttpResult();
            try
            {
                SetRequest(item);
            }
            catch (Exception ex)
            {
                result = new HttpResult();
                result.Cookie = string.Empty;
                result.Header = null;
                result.Html = ex.Message;
                result.StatusDescription = "配置参数时出错:" + ex.Message;
                return result;
            }
            #endregion

            #region 开始请求
            try
            {
                #region 如果是HTTPS请求
                //GC.Collect();//强制对所有垃圾进行回收
                if (item.URL.StartsWith("https", StringComparison.OrdinalIgnoreCase)) Util.SetCertificatePolicy();
                #endregion

                #region 获取请求内容
                using (response = (HttpWebResponse)request.GetResponse())
                {
                    result.StatusCode = response.StatusCode;
                    result.StatusDescription = response.StatusDescription;
                    result.Header = response.Headers;
                    if (response.Cookies != null) result.CookieCollection = response.Cookies;
                    if (response.Headers["Set-Cookie"] != null) result.Cookie = Utilities.LiteCookies(response.Headers["Set-Cookie"]);
                    if (response.Headers["Location"] != null)                               //出现跳转时
                    {
                        result.Location = response.Headers["Location"];
                        if (!result.Location.StartsWith("http"))
                        {
                            string[] tem = item.URL.Split('/');
                            if (result.Location.StartsWith("//"))
                                result.Location = tem[0] + result.Location;
                            else
                                result.Location = item.URL.Replace(tem[tem.Length - 1], "") + result.Location;
                        }
                        #region 如果允许自动跳转,则执行重定向链接直到结束
                        if (item.AutoJump)
                        {
                            item.URL = result.Location;
                            item.Method = "GET";
                            LastJumpUrl = item.URL;
                            if (JumpCookies == "" && item.Cookie != "") JumpCookies = item.Cookie;
                            if (result.Cookie != "")
                            {
                                JumpCookies = Utilities.MergerCookies(JumpCookies, result.Cookie);
                                item.Cookie = JumpCookies;
                            }
                            IsRedirect = true;
                            goto Redirect;
                        }
                        #endregion

                    }
                    else
                    {
                        byte[] ResponseByte = GetResponseBytes(response);                   //获取返回的Byte数组
                        if (ResponseByte != null & ResponseByte.Length > 0)
                        {
                            if (item.ResultType == ResultType.Byte)                         //直接返回字节数组,Html内容不再获取
                                result.ResultByte = ResponseByte;
                            else
                            {
                                if (!string.IsNullOrEmpty(response.Headers["Content-Type"]))
                                {
                                    string encode = response.Headers["Content-Type"];       //从返回头中获取编码格式
                                    if (encode.ToLower().Contains("charset="))
                                    {
                                        encode = encode.Split('=')[1];
                                        if (!string.IsNullOrEmpty(encode)) encoding = GetEncode(encode.ToUpper());//获取编码格式
                                    }
                                }
                                if (encoding == null) encoding = GetEncoding(ResponseByte); //未指定编码时自动获取网页编码格式
                                result.Html = encoding.GetString(ResponseByte);
                            }
                        }
                        else
                        {
                            result.Html = "本次请求并未返回任何数据";
                        }
                    }
                    //if(!string.IsNullOrEmpty(response.Headers["Date"]))result.DataTime=Utilities.GetNetTime(response.Headers["Date"]);//返回网络时间
                }
                #endregion

            }
            #endregion

            #region 异常捕获
            catch (WebException ex)
            {
                response = (HttpWebResponse)ex.Response;
                result.Html = ex.Message;
                if (response != null)
                {
                    result.StatusCode = response.StatusCode;
                    result.StatusDescription = response.StatusDescription;
                }
                try
                {
                    #region 获取异常情况返回的源码
                    switch (response.StatusCode)
                    {
                        case HttpStatusCode.NotFound: break;     //404
                        case HttpStatusCode.InternalServerError: //500
                            if (response != null)
                            {
                                byte[] ResponseByte = GetResponseBytes(response);
                                encoding = GetEncoding(ResponseByte);
                                result.Html = encoding.GetString(ResponseByte);
                            }
                            break;
                        default: break;
                    }
                    #endregion

                }
                catch { }
            }
            catch (Exception ex)
            {
                result.Html = ex.Message;
            }
            #endregion

            #region 数据返回
            if (item.IsToLower) result.Html = result.Html.ToLower();
            #region 如果允许自动跳转,返回重定向过程中产生的Cookie及最后链接
            if (IsRedirect)
            {
                result.Cookie = Utilities.MergerCookies(JumpCookies, result.Cookie);
                result.LastJumpUrl = LastJumpUrl;
            }
            #endregion

            return result;
            #endregion

        }
        #endregion

        #region Gzip格式自动解压,返回Byte数组
        private byte[] GetResponseBytes(HttpWebResponse response)
        {
            MemoryStream _stream = new MemoryStream();
            if (response.ContentEncoding != null && response.ContentEncoding.Equals("gzip", StringComparison.InvariantCultureIgnoreCase))//GZIIP处理
                _stream = GetMemoryStream(new GZipStream(response.GetResponseStream(), CompressionMode.Decompress));
            else
                _stream = GetMemoryStream(response.GetResponseStream());
            byte[] ResponseByte = _stream.ToArray();
            _stream.Close();
            return ResponseByte;
        }
        #endregion

        #region 自动获取编码
        private Encoding GetEncoding(byte[] ResponseByte)
        {
            Encoding encoding = Encoding.Default;
            Match meta = Regex.Match(Encoding.Default.GetString(ResponseByte), "<meta([^<]*)charset=([^<]*)[\"']", RegexOptions.IgnoreCase);
            string c = (meta.Groups.Count > 1) ? meta.Groups[2].Value.ToLower().Trim() : string.Empty;
            if (c.Length > 2)
            {
                try
                {
                    if (c.IndexOf(" ") > 0) c = c.Substring(0, c.IndexOf(" "));
                    encoding = Encoding.GetEncoding(c.Replace("\"", "").Replace("'", "").Replace(";", "").Replace("iso-8859-1", "gbk").Trim());
                }
                catch
                {
                    if (!string.IsNullOrEmpty(response.CharacterSet))
                        encoding = GetEncode(response.CharacterSet.ToUpper());
                    else
                        encoding = Encoding.UTF8;
                }
            }
            else
            {
                if (!string.IsNullOrEmpty(response.CharacterSet))
                    encoding = GetEncode(response.CharacterSet.ToUpper());
                else
                    encoding = Encoding.UTF8;
            }
            return encoding;
        }
        private Encoding GetEncode(string charset)
        {
            switch (charset)
            {
                case "ASCII": return Encoding.ASCII;
                case "UNICODE": return Encoding.Unicode;
                case "UTF7": return Encoding.UTF7;
                case "UTF8": return Encoding.UTF8;
                case "UTF32": return Encoding.UTF32;
                case "GB2312": return Encoding.GetEncoding("GB2312");
                case "GBK": return Encoding.GetEncoding("GBK");
                //case "ISO-8859-1": return Encoding.GetEncoding("GBK");
                default: return Encoding.UTF8;
            }
        }
        #endregion

        #region 获取内存流
        private MemoryStream GetMemoryStream(Stream streamResponse)
        {
            MemoryStream _stream = new MemoryStream();
            int Length = 256;
            Byte[] buffer = new Byte[Length];
            int bytesRead = streamResponse.Read(buffer, 0, Length);
            while (bytesRead > 0)
            {
                _stream.Write(buffer, 0, bytesRead);
                bytesRead = streamResponse.Read(buffer, 0, Length);
            }
            return _stream;
        }
        #endregion

        #region 准备请求参数
        private void SetRequest(HttpItem item)
        {
            SetCer(item);                                      //验证证书
            if (item.Header != null && item.Header.Count > 0) foreach (string key in item.Header.AllKeys) { request.Headers.Add(key, item.Header[key]); }//设置Header参数
            SetProxy(item);                                    //设置代理
            if (item.ProtocolVersion != null) request.ProtocolVersion = item.ProtocolVersion;
            request.ServicePoint.Expect100Continue = item.Expect100Continue;
            request.Method = item.Method;                      //请求方式Get或者Post
            request.Timeout = item.Timeout;                    //超时时间
            request.KeepAlive = item.KeepAlive;                //保持连接状态
            request.ReadWriteTimeout = item.ReadWriteTimeout;  //读写超时时间
            request.Accept = item.Accept;                      //接收数据类型
            if (item.Method.ToLower() == "post") request.ContentType = item.ContentType;//ContentType返回类型
            request.UserAgent = item.UserAgent;                //UserAgent客户端的访问类型，包括浏览器版本和操作系统信息
            encoding = item.Encoding;                          //指定的编码
            request.Credentials = item.ICredentials;           //设置安全凭证
            SetCookie(item);                                   //设置Cookie
            request.Referer = item.Referer;                    //来源地址
            request.AllowAutoRedirect = item.Allowautoredirect;//是否执行跳转功能
            SetPostData(item);                                 //设置Post数据
            if (item.Connectionlimit > 0) request.ServicePoint.ConnectionLimit = item.Connectionlimit;//设置最大连接
        }
        #endregion

        #region 设置证书
        private void SetCer(HttpItem item)
        {
            if (!string.IsNullOrEmpty(item.CerPath))
            {
                ServicePointManager.ServerCertificateValidationCallback = new System.Net.Security.RemoteCertificateValidationCallback(CheckValidationResult);
                request = (HttpWebRequest)WebRequest.Create(item.URL);
                SetCerList(item);
                request.ClientCertificates.Add(new X509Certificate(item.CerPath));
            }
            else
            {
                request = (HttpWebRequest)WebRequest.Create(item.URL);
                SetCerList(item);
            }
        }
        private void SetCerList(HttpItem item)
        {
            if (item.ClentCertificates != null && item.ClentCertificates.Count > 0)
            {
                foreach (X509Certificate c in item.ClentCertificates) { request.ClientCertificates.Add(c); }
            }
        }
        #endregion

        #region 设置Cookie
        private void SetCookie(HttpItem item)
        {
            if (!string.IsNullOrEmpty(item.Cookie))
            {
                item.Cookie = item.Cookie.Trim();
                if (item.Cookie.EndsWith(";")) item.Cookie = item.Cookie.Substring(0, item.Cookie.Length - 1);
                request.Headers[HttpRequestHeader.Cookie] = item.Cookie;
            }
            if (item.ResultCookieType == ResultCookieType.CookieCollection)
            {
                request.CookieContainer = new CookieContainer();
                if (item.CookieCollection != null && item.CookieCollection.Count > 0) request.CookieContainer.Add(item.CookieCollection);
            }
        }
        #endregion

        #region 设置Post数据
        private void SetPostData(HttpItem item)
        {
            if (request.Method.Trim().ToLower().Contains("post"))
            {
                if (item.PostEncoding != null) postencoding = item.PostEncoding;
                byte[] buffer = null;
                if (item.PostDataType == PostDataType.Byte && item.PostdataByte != null && item.PostdataByte.Length > 0)
                    buffer = item.PostdataByte;
                else if (item.PostDataType == PostDataType.FilePath && !string.IsNullOrEmpty(item.Postdata))
                {
                    StreamReader r = new StreamReader(item.Postdata, postencoding);
                    buffer = postencoding.GetBytes(r.ReadToEnd());
                    r.Close();
                }
                else if (!string.IsNullOrEmpty(item.Postdata))
                    buffer = postencoding.GetBytes(item.Postdata);
                if (buffer != null)
                {
                    request.ContentLength = buffer.Length;
                    request.GetRequestStream().Write(buffer, 0, buffer.Length);
                }
            }
        }
        #endregion

        #region 设置代理
        private void SetProxy(HttpItem item)
        {
            bool isIeProxy = false;
            if (!string.IsNullOrEmpty(item.ProxyIp))
            {
                isIeProxy = item.ProxyIp.ToLower().Contains("ieproxy");
            }
            if (!string.IsNullOrEmpty(item.ProxyIp) && !isIeProxy)
            {
                if (item.ProxyIp.Contains(":"))
                {
                    string[] plist = item.ProxyIp.Split(':');
                    WebProxy myProxy = new WebProxy(plist[0].Trim(), Convert.ToInt32(plist[1].Trim()));
                    myProxy.Credentials = new NetworkCredential(item.ProxyUserName, item.ProxyPwd);
                    request.Proxy = myProxy;
                }
                else
                {
                    WebProxy myProxy = new WebProxy(item.ProxyIp, false);
                    myProxy.Credentials = new NetworkCredential(item.ProxyUserName, item.ProxyPwd);
                    request.Proxy = myProxy;
                }
            }
            else if (isIeProxy)
            {
                //设置为IE代理
            }
            else
            {
                request.Proxy = item.WebProxy;
            }
        }
        #endregion

        #region HTTPS网站请求及回调验证证书
        public static class Util
        {
            public static void SetCertificatePolicy() { ServicePointManager.ServerCertificateValidationCallback += RemoteCertificateValidate; }
            public static bool RemoteCertificateValidate(object sender, X509Certificate cert, X509Chain chain, SslPolicyErrors error) { return true; }
        }
        public static bool CheckValidationResult(object sender, X509Certificate certificate, X509Chain chain, SslPolicyErrors errors) { return true; }
        #endregion

    }
    #region 请求类
    public class HttpItem
    {
        #region 请求URL
        string _URL = string.Empty;
        public string URL
        {
            get { return _URL; }
            set { _URL = value; }
        }
        #endregion

        #region 请求方式
        string _Method = "GET";
        public string Method
        {
            get { return _Method; }
            set { _Method = value; }
        }
        #endregion

        #region 默认请求超时时间
        int _Timeout = 100000;
        public int Timeout
        {
            get { return _Timeout; }
            set { _Timeout = value; }
        }
        #endregion

        #region 默认写入Post数据超时时间
        int _ReadWriteTimeout = 30000;
        public int ReadWriteTimeout
        {
            get { return _ReadWriteTimeout; }
            set { _ReadWriteTimeout = value; }
        }
        #endregion

        #region 建立持久性连接
        Boolean _KeepAlive = true;
        public Boolean KeepAlive
        {
            get { return _KeepAlive; }
            set { _KeepAlive = value; }
        }
        #endregion

        #region 请求头
        string _Accept = "text/html,application/xhtml+xml,*/*";
        public string Accept
        {
            get { return _Accept; }
            set { _Accept = value; }
        }
        #endregion

        #region 请求响应的HTTP内容类型
        string _ContentType = "application/x-www-form-urlencoded";
        public string ContentType
        {
            get { return _ContentType; }
            set { _ContentType = value; }
        }
        #endregion

        #region 浏览器类型
        //string _UserAgent = "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.95 Safari/537.36";
        //string _UserAgent = "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/45.0.2454.101 Safari/537.36";
        string _UserAgent = "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/45.0.2454.101 Safari/537.36";
        public string UserAgent
        {
            get { return _UserAgent; }
            set { _UserAgent = value; }
        }
        #endregion

        #region 网页数据编码
        Encoding _Encoding = null;
        public Encoding Encoding
        {
            get { return _Encoding; }
            set { _Encoding = value; }
        }
        #endregion

        #region Post的数据类型
        private PostDataType _PostDataType = PostDataType.String;
        public PostDataType PostDataType
        {
            get { return _PostDataType; }
            set { _PostDataType = value; }
        }
        #endregion

        #region Post数据--字符串
        string _Postdata = string.Empty;
        public string Postdata
        {
            get { return _Postdata; }
            set { _Postdata = value; }
        }
        #endregion

        #region Post数据--Byte
        private byte[] _PostdataByte = null;
        public byte[] PostdataByte
        {
            get { return _PostdataByte; }
            set { _PostdataByte = value; }
        }
        #endregion

        #region 代理对象
        private WebProxy _WebProxy = null;
        public WebProxy WebProxy
        {
            get { return _WebProxy; }
            set { _WebProxy = value; }
        }
        #endregion

        #region 代理服务器用户名
        private string proxyusername = string.Empty;
        public string ProxyUserName
        {
            get { return proxyusername; }
            set { proxyusername = value; }
        }
        #endregion

        #region 代理服务器密码
        private string proxypwd = string.Empty;
        public string ProxyPwd
        {
            get { return proxypwd; }
            set { proxypwd = value; }
        }
        #endregion

        #region 如果要使用IE代理就设置为ieproxy
        private string proxyip = string.Empty;
        public string ProxyIp
        {
            get { return proxyip; }
            set { proxyip = value; }
        }
        #endregion

        #region Cookie对象集合
        CookieCollection cookiecollection = null;
        public CookieCollection CookieCollection
        {
            get { return cookiecollection; }
            set { cookiecollection = value; }
        }
        #endregion

        #region 请求时的Cookie
        string _Cookie = string.Empty;
        public string Cookie
        {
            get { return _Cookie; }
            set { _Cookie = value; }
        }
        #endregion

        #region 来源地址
        string _Referer = string.Empty;
        public string Referer
        {
            get { return _Referer; }
            set { _Referer = value; }
        }
        #endregion

        #region 证书绝对路径
        string _CerPath = string.Empty;
        public string CerPath
        {
            get { return _CerPath; }
            set { _CerPath = value; }
        }
        #endregion

        #region 全文是否转小写
        private Boolean isToLower = false;
        public Boolean IsToLower
        {
            get { return isToLower; }
            set { isToLower = value; }
        }
        #endregion

        #region 是否允许重定向
        private Boolean allowautoredirect = false;
        public Boolean Allowautoredirect
        {
            get { return allowautoredirect; }
            set { allowautoredirect = value; }
        }
        #endregion

        #region 是否自动执行跳转
        private Boolean autoJump = true;
        public Boolean AutoJump
        {
            get { return autoJump; }
            set { autoJump = value; }
        }
        #endregion

        #region 最大连接数
        private int connectionlimit = 1024;
        public int Connectionlimit
        {
            get { return connectionlimit; }
            set { connectionlimit = value; }
        }
        #endregion

        #region 返回类型
        private ResultType resulttype = ResultType.String;
        public ResultType ResultType
        {
            get { return resulttype; }
            set { resulttype = value; }
        }
        #endregion

        #region header对象
        private WebHeaderCollection header = new WebHeaderCollection();
        public WebHeaderCollection Header
        {
            get { return header; }
            set { header = value; }
        }
        #endregion

        #region HTTP 版本
        private Version _ProtocolVersion = HttpVersion.Version11;
        public Version ProtocolVersion
        {
            get { return _ProtocolVersion; }
            set { _ProtocolVersion = value; }
        }
        #endregion

        #region 是否使用100-Continue
        private Boolean _expect100continue = false;
        public Boolean Expect100Continue
        {
            get { return _expect100continue; }
            set { _expect100continue = value; }
        }
        #endregion

        #region 设置509证书集合
        private X509CertificateCollection _ClentCertificates;
        public X509CertificateCollection ClentCertificates
        {
            get { return _ClentCertificates; }
            set { _ClentCertificates = value; }
        }
        #endregion

        #region Post参数编码
        private Encoding _PostEncoding;
        public Encoding PostEncoding
        {
            get { return _PostEncoding; }
            set { _PostEncoding = value; }
        }
        #endregion

        #region Cookie返回类型
        private ResultCookieType _ResultCookieType = ResultCookieType.String;
        public ResultCookieType ResultCookieType
        {
            get { return _ResultCookieType; }
            set { _ResultCookieType = value; }
        }
        #endregion

        #region 身份验证信息
        private ICredentials _ICredentials = CredentialCache.DefaultCredentials;
        public ICredentials ICredentials
        {
            get { return _ICredentials; }
            set { _ICredentials = value; }
        }
        #endregion

    }
    #endregion

    #region 返回类
    public class HttpResult
    {
        #region 返回的Cookie字符串
        private string _Cookie;
        public string Cookie
        {
            get { return _Cookie; }
            set { _Cookie = value; }
        }
        #endregion

        #region 返回LastJumpUrl
        private string _LastJumpUrl;
        public string LastJumpUrl
        {
            get { return _LastJumpUrl; }
            set { _LastJumpUrl = value; }
        }
        #endregion

        #region 返回的Cookie对象集合
        private CookieCollection _CookieCollection;
        public CookieCollection CookieCollection
        {
            get { return _CookieCollection; }
            set { _CookieCollection = value; }
        }
        #endregion

        #region 返回的String类型
        private string _Html;
        public string Html
        {
            get { return _Html; }
            set { _Html = value; }
        }
        #endregion

        #region 返回的Byte数组
        private byte[] _ResultByte;
        public byte[] ResultByte
        {
            get { return _ResultByte; }
            set { _ResultByte = value; }
        }
        #endregion

        #region 新增返回参数Location
        private string _Location;
        public string Location
        {
            get { return _Location; }
            set { _Location = value; }
        }
        #endregion

        #region 新增网络时间参数DataTime
        private string _DataTime;
        public string DataTime
        {
            get { return _DataTime; }
            set { _DataTime = value; }
        }
        #endregion

        #region Header集合
        private WebHeaderCollection _Header;
        public WebHeaderCollection Header
        {
            get { return _Header; }
            set { _Header = value; }
        }
        #endregion

        #region 返回状态说明
        private string _StatusDescription;
        public string StatusDescription
        {
            get { return _StatusDescription; }
            set { _StatusDescription = value; }
        }
        #endregion

        #region 返回状态码
        private HttpStatusCode _StatusCode;
        public HttpStatusCode StatusCode
        {
            get { return _StatusCode; }
            set { _StatusCode = value; }
        }
        #endregion

    }
    #endregion

    #region 返回类型
    #region 返回数据类型
    public enum ResultType { String, Byte }
    #endregion

    #region Post的数据格式
    public enum PostDataType { String, Byte, FilePath }
    #endregion

    #region Cookie返回类型
    public enum ResultCookieType { String, CookieCollection }
    #endregion

    #endregion

}