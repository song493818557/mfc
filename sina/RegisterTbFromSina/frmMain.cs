/*
 本工程代码为自动生成,链接部分需要根据抓包自行修改.
 Create By 309363537
*/
using System;
using System.Reflection;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading;
using System.Windows.Forms;

#region Utilities类函数
/*
    一、编解码函数
        ----UTF8编码
        ----%uxxxx编码
        ----&#xxxx|%uxxxx|%AB%CD解码
        ----MD5加密
    二、Byte数组转图片
    三、字符串操作函数
        ----处理Cookie
        ----过滤html标签
        ----取中间字符串
        ----字符串倒序输出
    四、时间操作函数
        ----时间戳
        ----获取网络时间
        ----时间相加
        ----英文月份变数字月份
*/
#endregion

namespace RegisterTbFromSina
{
    public partial class frmMain : Form
    {
        #region 变量定义及界面初始化
        HttpHelper http = new HttpHelper();
        HttpItem item = null;
        HttpResult result = null;
        bool ChangeMobile = false;//更换手机号
        string Cookies = "";
        string retCode = "";
        string VCode = "";
        string mobileCode = "";
        string wbEmail = "";
        string wbPass = "";
        string tbNick = "";
        string tbPass = "";
        string mobile = "";
        public frmMain()
        {
            InitializeComponent();
            string[] account = "btxksqadtakq0@sina.com|teflfd161636".Split('|');
            txtwbEmail.Text = account[0];
            txtwbPass.Text = account[1];
            txttbNick.Text = "jscjren5698";
            txttbPass.Text = "jscjgs2000";
            txtmobile.Text = "15819434892";
            string aa = Utilities.DecodeFromASCII();
        }
        #endregion

        #region 开始注册
        private void button1_Click(object sender, EventArgs e)
        {
            #region 赋值及检查是否为空
            wbEmail = txtwbEmail.Text;
            wbPass = txtwbPass.Text;
            tbNick = txttbNick.Text;
            tbPass = txttbPass.Text;
            mobile = txtmobile.Text;
            if (string.IsNullOrEmpty(wbEmail))
            {
                txtwbEmail.Focus();
                return;
            }
            if (string.IsNullOrEmpty(wbPass))
            {
                txtwbPass.Focus();
                return;
            }
            if (string.IsNullOrEmpty(tbNick))
            {
                txttbNick.Focus();
                return;
            }
            if (string.IsNullOrEmpty(tbPass))
            {
                txttbPass.Focus();
                return;
            }
            if (string.IsNullOrEmpty(mobile))
            {
                txtmobile.Focus();
                return;
            }
            #endregion

            #region 首页
            button1.Enabled = false;
            string su = Utilities.UTF8(Utilities.GetBase64(wbEmail));
            item = new HttpItem()
            {
                URL = "https://login.taobao.com/member/login.jhtml",
                Method = "GET",
                Accept = "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*",
            };
            result = http.GetHtml(item);
            string FirstCookies = Utilities.MergerCookies("", result.Cookie);
            retCode = result.Html;
            string spm = GetSPM();
            string cache = makeCacheNum();
            string url = "http://weibo.com/" + Utilities.GetMidStr(retCode, "http://weibo.com/", "\"").Replace("?entry", "?spm=a2107.1.0.0." + spm + "&entry");
            string trid = Utilities.GetMidStr(retCode, "&&trid=", "\"");
            #endregion

            #region 新增请求
            //item = new HttpItem()//新增
            //{
            //    URL = "https://log.mmstat.com/1.gif?logtype=1&title=%u6DD8%u5B9D%u7F51%20-%20%u6DD8%uFF01%u6211%u559C%u6B22&pre=&cache=" + cache +
            //    "&scr=1600x900&spm-cnt=a2107.1.0.0." + spm + "&isbeta=3&category=&uidaplus=&aplus&yunid=&&trid=" + trid +
            //    "&p=1&o=winXP&b=chrome45&s=1600x900&w=webkit&ism=pc",
            //    Method = "GET",
            //    Accept = "image/webp,image/*,*/*",
            //    Referer = "https://login.taobao.com/member/login.jhtml"
            //};
            //item.Header.Add("Accept-Language", "zh-CN,zh");
            //result = http.GetHtml(item);
            //Cookies = Utilities.MergerCookies("", result.Cookie);
            //retCode = result.Html;

            //cache:function makeCacheNum(){return Math.floor(268435456*Math.random()).toString(16)}
            //URL = "https://log.mmstat.com/1.gif?logtype=1&title=%u6DD8%u5B9D%u7F51%20-%20%u6DD8%uFF01%u6211%u559C%u6B22&pre=&cache=a99fa87&scr=1600x900&spm-cnt=a2107.1.0.0." + spm + "&isbeta=3&category=&uidaplus=&aplus&yunid=&&trid=" + trid + "&p=1&o=winXP&b=chrome45&s=1600x900&w=webkit&ism=pc",
            //新增:https://log.mmstat.com/1.gif?logtype=1&title=%u6DD8%u5B9D%u7F51%20-%20%u6DD8%uFF01%u6211%u559C%u6B22&pre=&cache=1ec968b&scr=1440x900&cna=DpaPDu4JhB0CATrZXgGgp+nG&spm-cnt=a2107.1.0.0.43BKyT&isbeta=3&category=&uidaplus=&aplus&yunid=&&trid=0ab251bc14447200635581872e&asid=AQAAAAC/rRxWbadqTAAAAACW1n5ONANtMA==&p=1&o=win7&b=chrome45&s=1440x900&w=webkit&ism=pc
            //新增:https://log.mmstat.com/1.gif?logtype=1&title=%u6DD8%u5B9D%u7F51%20-%20%u6DD8%uFF01%u6211%u559C%u6B22&pre=&cache=a99fa87&scr=1600x900&spm-cnt=a2107.1.0.0." + spm + "&isbeta=3&category=&uidaplus=&aplus&yunid=&&trid=0ab21b6a14450107285418057e&asid=AQAAAAAoHSFWb1YVbgAAAADfJ+W6GOprAQ==&p=1&o=winXP&b=chrome45&s=1600x900&w=webkit&ism=pc
            //新增:https://gm.mmstat.com/ahot.1.1?logtype=2&cache=0.5418655886314809&p=1&o=win7&b=chrome39&w=webkit&s=1440x900&mx=&spm-cnt=a2107.1.43BKyT&isps=1&trid=0ab251bc14447200635581872e&lee=3353&les=3344&dc=3344&dclee=939&dcles=938&di=938&dl=657&rpe=656&rps=655&rqs=639&scs=na&ce=635&cs=635&dle=635&dls=635&fs=635&rde=na&rds=na&uee=na&ues=na&ns=0&fp=1704
            //新增:https://log.mmstat.com/1.gif?logtype=1&title=%u6DD8%u5B9D%u7F51%20-%20%u6CE8%u518C&pre=http%3A%2F%2Fweibo.com%2Flogin.php%3Fspm%3Da2107.1.0.0.43BKyT%26entry%3Dtaobao%26goto%3Dhttps%253A%252F%252Flogin.taobao.com%252Faso%252Ftvs%253Fdomain%253Dweibo%2526sid%253D1852abcf4060521cf9f1ba002dad409d%2526target%253D%26goto2%3D&cache=5f14c32&scr=1440x900&cna=DpaPDu4JhB0CATrZXgGgp+nG&spm-pre=a2107.1.0.0.43BKyT&spm-cnt=a2145.5765665.0.0.aTT9Gt&isbeta=3&category=&uidaplus=&aplus&thw=cn&p=1&o=win7&b=chrome39&s=1440x900&w=webkit&ism=pc
            //新增:https://log.mmstat.com/f.gif?logtype=1&title=Loading...&pre=https%3A%2F%2Freg.taobao.com%2Fmember%2Fsina%2Fsina_activation.htm&cache=5f27aa7&scr=1440x900&spm-cnt=0.0.0.0.dDtOdi&isbeta=3&category=&uidaplus=&aplus&yunid=&&trid=0ab3ae2c14447201879826576e&asid=AQAAAAA7rhxW5m93DgAAAADwv8Kilnjk8Q==&p=1&o=win7&b=chrome39&s=1440x900&w=webkit&ism=pc
            #endregion

            #region 微博登录方式
            item = new HttpItem()
            {
                //新增
                URL = url,
                Method = "GET",
                Accept = "image/webp,image/*,*/*",
                Referer = "https://login.taobao.com/member/login.jhtml"
            };
            item.Header.Add("Accept-Language", "zh-CN,zh");
            result = http.GetHtml(item);
            Cookies = Utilities.MergerCookies(Cookies, result.Cookie);
            retCode = result.Html;
            #endregion

            #region 取参数变量
            item = new HttpItem()
            {
                //URL = "http://login.sina.com.cn/sso/prelogin.php?entry=weibo&callback=sinaSSOController.preloginCallBack&su=" + su + "&rsakt=mod&checkpin=1&client=ssologin.js(v1.4.18)&_=" + Utilities.GetTime(),
                URL = "http://login.sina.com.cn/sso/prelogin.php?entry=weibo&callback=sinaSSOController.preloginCallBack&su=&rsakt=mod&client=ssologin.js(v1.4.18)&_=" + Utilities.GetTime(),
                Method = "GET",
                Accept = "*/*",
                Referer = url,
                //Cookie = Cookies
            };
            item.Header.Add("Accept-Language", "zh-CN,zh");
            result = http.GetHtml(item);
            Cookies = Utilities.MergerCookies(Cookies, result.Cookie);
            retCode = result.Html;//PublicKey
            string servertime = Utilities.GetMidStr(retCode, "servertime\":", ",");
            string pcid = Utilities.GetMidStr(retCode, "pcid\":\"", "\"");
            string nonce = Utilities.GetMidStr(retCode, "nonce\":\"", "\"");
            string pubkey = Utilities.GetMidStr(retCode, "pubkey\":\"", "\"");
            string rsakv = Utilities.GetMidStr(retCode, "rsakv\":\"", "\"");
            string sid = Utilities.GetMidStr(url, "sid%3D", "%");
            string sp = SinaEncrypt(servertime, nonce, wbPass);
            #endregion

            #region 开始登录
            item = new HttpItem()
            {
                URL = "http://login.sina.com.cn/sso/login.php?client=ssologin.js(v1.4.18)",
                Method = "POST",
                Accept = "text/html,application/xhtml+xml,application/xml,image/webp,*/*",
                Referer = "http://weibo.com/ajaxlogin.php?entry=taobao&action=4&url=https%3A%2F%2Flogin.taobao.com%2Faso%2Ftvs%3Fdomain%3Dweibo%26sid%3D" + sid + "%26target%3D&framelogin=1&callback=parent.sinaSSOController.feedBackUrlCallBack",
                Cookie = Cookies,
                Postdata = "entry=weibo&gateway=1&from=&savestate=7&useticket=1&pagerefer=&vsnf=1&su=" + su + "&service=miniblog&servertime=" + servertime +
                "&nonce=" + nonce + "&pwencode=rsa2&rsakv=" + rsakv + "&sp=" + sp + "&sr=1400*1050&encoding=UTF-8&prelt=71&url=http%3A%2F%2Fweibo.com%2Fajaxlogin.php%3Fentry%3Dtaobao%26action%3D4%26url%3Dhttps%253A%252F%252Flogin.taobao.com%252Faso%252Ftvs%253Fdomain%253Dweibo%2526sid%253D" + sid + "%2526target%253D%26framelogin%3D1%26callback%3Dparent.sinaSSOController.feedBackUrlCallBack&returntype=META"
            };
            result = http.GetHtml(item);
            Cookies = Utilities.MergerCookies(Cookies, result.Cookie);
            retCode = result.Html;
            #endregion

            #region 登录结果判断
            if (!retCode.Contains("正在登录 ..."))//需要验证码
            {
                #region 第一步,跳转1次
                url = Utilities.GetMidStr(retCode, "location.replace(\"", "\"");
                //http://weibo.com/ajaxlogin.php?entry=taobao&action=4&url=https%3A%2F%2Flogin.taobao.com%2Faso%2Ftvs%3Fdomain%3Dweibo%26sid%3D226cb1df7364b2d1f299d2da5fdf0aa4%26target%3D&framelogin=1&callback=parent.sinaSSOController.feedBackUrlCallBack&sudaref=weibo.com&retcode=4049&reason=%CE%AA%C1%CB%C4%FA%B5%C4%D5%CA%BA%C5%B0%B2%C8%AB%A3%AC%C7%EB%CA%E4%C8%EB%D1%E9%D6%A4%C2%EB
                item = new HttpItem()
                {
                    URL = url,
                    Method = "GET",
                    Accept = "text/html,application/xhtml+xml,application/xml,image/webp,*/*",
                    Referer = "http://login.sina.com.cn/sso/login.php?client=ssologin.js(v1.4.18)",
                    Cookie = Cookies
                };
                item.Header.Add("Accept-Language", "zh-CN,zh");
                result = http.GetHtml(item);
                Cookies = Utilities.MergerCookies(Cookies, result.Cookie);
                retCode = result.Html;
                string referer = result.LastJumpUrl;
                #endregion

                #region 第二步
                item = new HttpItem()
                {
                    URL = "http://passport.weibo.com/visitor/genvisitor",
                    Method = "POST",
                    Accept = "*/*",
                    Referer = referer,
                    Postdata = "cb=gen_callback&fp=%7B%22os%22%3A%221%22%2C%22browser%22%3A%22Chrome39%2C0%2C2171%2C95%22%2C%22fonts%22%3A%2204b_21%2CAcadEref%2CAgency%20FB%2CAharoni%2CAIGDT%2CAlgerian%2CAmdtSymbols%2CAMGDT%2CAndalus%2CAngsana%20New%2CAngsanaUPC%2CAparajita%2CArabic%20Typesetting%2CArial%2CArial%20Black%2CArial%20Narrow%2CArial%20Rounded%20MT%20Bold%2CArial%20Unicode%20MS%2CBankGothic%20Lt%20BT%2CBankGothic%20Md%20BT%2CBaskerville%20Old%20Face%2CBatang%2CBatangChe%2CBauhaus%2093%2CBell%20MT%2CBerlin%20Sans%20FB%2CBerlin%20Sans%20FB%20Demi%2CBernard%20MT%20Condensed%2CBitstream%20Vera%20Sans%20Mono%2CBlackadder%20ITC%2CBodoni%20MT%2CBodoni%20MT%20Black%2CBodoni%20MT%20Condensed%2CBodoni%20MT%20Poster%20Compressed%2CBook%20Antiqua%2CBookman%20Old%20Style%2CBookshelf%20Symbol%207%2CBradley%20Hand%20ITC%2CBritannic%20Bold%2CBroadway%2CBrowallia%20New%2CBrowalliaUPC%2CBrush%20Script%20MT%2CCalibri%2CCalifornian%20FB%2CCalisto%20MT%2CCambria%2CCambria%20Math%2CCandara%2CCastellar%2CCentaur%2CCentury%2CCentury%20Gothic%2CCentury%20Schoolbook%2CChiller%2CCityBlueprint%2CColonna%20MT%2CComic%20Sans%20MS%2CCommercialPi%20BT%2CCommercialScript%20BT%2CComplex%2CConsolas%2CConstantia%2CCooper%20Black%2CCopperplate%20Gothic%20Bold%2CCopperplate%20Gothic%20Light%2CCorbel%2CCordia%20New%2CCordiaUPC%2CCountryBlueprint%2CCourier%2CCourier%20New%2CCurlz%20MT%2CDaunPenh%2CDavid%2CDFKai-SB%2CDilleniaUPC%2CDokChampa%2CDotum%2CDotumChe%2CDutch801%20Rm%20BT%2CDutch801%20XBd%20BT%2CEbrima%2CEdwardian%20Script%20ITC%2CElephant%2CEngravers%20MT%2CEras%20Bold%20ITC%2CEras%20Demi%20ITC%2CEras%20Light%20ITC%2CEras%20Medium%20ITC%2CEstrangelo%20Edessa%2CEucrosiaUPC%2CEuphemia%2CEuroRoman%2CFelix%20Titling%2CFixedsys%2CFootlight%20MT%20Light%2CForte%2CFranklin%20Gothic%20Book%2CFranklin%20Gothic%20Demi%2CFranklin%20Gothic%20Demi%20Cond%2CFranklin%20Gothic%20Heavy%2CFranklin%20Gothic%20Medium%2CFranklin%20Gothic%20Medium%20Cond%2CFrankRuehl%2CFreesiaUPC%2CFreestyle%20Script%2CFrench%20Script%20MT%2CGabriola%2CGaramond%2CGautami%2CGDT%2CGeorgia%2CGigi%2CGill%20Sans%20MT%2CGill%20Sans%20MT%20Condensed%2CGill%20Sans%20MT%20Ext%20Condensed%20Bold%2CGill%20Sans%20Ultra%20Bold%2CGill%20Sans%20Ultra%20Bold%20Condensed%2CGisha%2CGloucester%20MT%20Extra%20Condensed%2CGothicE%2CGothicG%2CGothicI%2CGoudy%20Old%20Style%2CGoudy%20Stout%2CGreekC%2CGreekS%2CGulim%2CGulimChe%2CGungsuh%2CGungsuhChe%2CHaettenschweiler%2CHarlow%20Solid%20Italic%2CHarrington%2CHigh%20Tower%20Text%2CImpact%2CImprint%20MT%20Shadow%2CInformal%20Roman%2CIrisUPC%2CIskoola%20Pota%2CISOCP%2CISOCP2%2CISOCP3%2CISOCPEUR%2CISOCT%2CISOCT2%2CISOCT3%2CISOCTEUR%2CItalic%2CItalicC%2CItalicT%2CJasmineUPC%2CJokerman%2CJuice%20ITC%2CKalinga%2CKartika%2CKhmer%20UI%2CKodchiangUPC%2CKokila%2CKristen%20ITC%2CKunstler%20Script%2CLao%20UI%2CLatha%2CLeelawadee%2CLevenim%20MT%2CLilyUPC%2CLucida%20Bright%2CLucida%20Calligraphy%2CLucida%20Console%2CLucida%20Fax%2CLucida%20Handwriting%2CLucida%20Sans%2CLucida%20Sans%20Typewriter%2CLucida%20Sans%20Unicode%2CMagneto%2CMaiandra%20GD%2CMalgun%20Gothic%2CMangal%2CMarlett%2CMatura%20MT%20Script%20Capitals%2CMeiryo%2CMeiryo%20UI%2CMicrosoft%20Himalaya%2CMicrosoft%20JhengHei%2CMicrosoft%20New%20Tai%20Lue%2CMicrosoft%20PhagsPa%2CMicrosoft%20Sans%20Serif%2CMicrosoft%20Tai%20Le%2CMicrosoft%20Uighur%2CMicrosoft%20Yi%20Baiti%2CMingLiU%2CMingLiU-ExtB%2CMingLiU_HKSCS%2CMingLiU_HKSCS-ExtB%2CMiriam%2CMiriam%20Fixed%2CMistral%2CModern%2CModern%20No.%2020%2CMongolian%20Baiti%2CMonospac821%20BT%2CMonotxt%2CMonotype%20Corsiva%2CMoolBoran%2CMS%20Gothic%2CMS%20Mincho%2CMS%20Outlook%2CMS%20PGothic%2CMS%20PMincho%2CMS%20Reference%20Sans%20Serif%2CMS%20Reference%20Specialty%2CMS%20Sans%20Serif%2CMS%20Serif%2CMS%20UI%20Gothic%2CMT%20Extra%2CMV%20Boli%2CNarkisim%2CNiagara%20Engraved%2CNiagara%20Solid%2CNyala%2COCR%20A%20Extended%2COld%20English%20Text%20MT%2COnyx%2CPalace%20Script%20MT%2CPalatino%20Linotype%2CPanRoman%2CPapyrus%2CParchment%2CPerpetua%2CPerpetua%20Titling%20MT%2CPlantagenet%20Cherokee%2CPlaybill%2CPMingLiU%2CPMingLiU-ExtB%2CPoor%20Richard%2CPristina%2CProxy%201%2CProxy%202%2CProxy%203%2CProxy%204%2CProxy%205%2CProxy%206%2CProxy%207%2CProxy%208%2CProxy%209%2CRaavi%2CRage%20Italic%2CRavie%2CRockwell%2CRockwell%20Condensed%2CRockwell%20Extra%20Bold%2CRod%2CRoman%2CRomanC%2CRomanD%2CRomanS%2CRomanT%2CRomantic%2CSakkal%20Majalla%2CSansSerif%2CScript%2CScript%20MT%20Bold%2CScriptC%2CScriptS%2CSegoe%20Print%2CSegoe%20Script%2CSegoe%20UI%2CSegoe%20UI%20Light%2CSegoe%20UI%20Semibold%2CSegoe%20UI%20Symbol%2CShonar%20Bangla%2CShowcard%20Gothic%2CShruti%2CSimplex%2CSimplified%20Arabic%2CSimplified%20Arabic%20Fixed%2CSimSun-ExtB%2CSmall%20Fonts%2CSnap%20ITC%2CStencil%2CStylus%20BT%2CSuperFrench%2CSwis721%20BdCnOul%20BT%2CSwis721%20BdOul%20BT%2CSwis721%20Blk%20BT%2CSwis721%20BlkCn%20BT%2CSwis721%20BlkEx%20BT%2CSwis721%20BlkOul%20BT%2CSwis721%20BT%2CSwis721%20Cn%20BT%2CSwis721%20Ex%20BT%2CSwis721%20Lt%20BT%2CSwis721%20LtCn%20BT%2CSwis721%20LtEx%20BT%2CSyastro%2CSylfaen%2CSymap%2CSymath%2CSymbol%2CSymeteo%2CSymusic%2CSystem%2CTahoma%2CTechnic%2CTechnicBold%2CTechnicLite%2CTempus%20Sans%20ITC%2CTerminal%2CTimes%20New%20Roman%2CTraditional%20Arabic%2CTrebuchet%20MS%2CTunga%2CTw%20Cen%20MT%2CTw%20Cen%20MT%20Condensed%2CTw%20Cen%20MT%20Condensed%20Extra%20Bold%2CTxt%2CUniversalMath1%20BT%2CUtsaah%2CVani%2CVerdana%2CVijaya%2CViner%20Hand%20ITC%2CVineta%20BT%2CVivaldi%2CVladimir%20Script%2CVrinda%2CWebdings%2CWide%20Latin%2CWingdings%2CWingdings%202%2CWingdings%203%2CZWAdobeF%2C%E4%BB%BF%E5%AE%8B%2C%E5%8D%8E%E6%96%87%E4%B8%AD%E5%AE%8B%2C%E5%8D%8E%E6%96%87%E4%BB%BF%E5%AE%8B%2C%E5%8D%8E%E6%96%87%E5%AE%8B%E4%BD%93%2C%E5%8D%8E%E6%96%87%E5%BD%A9%E4%BA%91%2C%E5%8D%8E%E6%96%87%E6%96%B0%E9%AD%8F%2C%E5%8D%8E%E6%96%87%E6%A5%B7%E4%BD%93%2C%E5%8D%8E%E6%96%87%E7%90%A5%E7%8F%80%2C%E5%8D%8E%E6%96%87%E7%BB%86%E9%BB%91%2C%E5%8D%8E%E6%96%87%E8%A1%8C%E6%A5%B7%2C%E5%8D%8E%E6%96%87%E9%9A%B6%E4%B9%A6%2C%E5%AE%8B%E4%BD%93%2C%E5%B9%BC%E5%9C%86%2C%E5%BE%AE%E8%BD%AF%E9%9B%85%E9%BB%91%2C%E6%96%B0%E5%AE%8B%E4%BD%93%2C%E6%96%B9%E6%AD%A3%E5%85%B0%E4%BA%AD%E8%B6%85%E7%BB%86%E9%BB%91%E7%AE%80%E4%BD%93%2C%E6%96%B9%E6%AD%A3%E5%A7%9A%E4%BD%93%2C%E6%96%B9%E6%AD%A3%E8%88%92%E4%BD%93%2C%E6%96%B9%E6%AD%A3%E8%A1%8C%E6%A5%B7%E7%AE%80%E4%BD%93%2C%E6%97%B6%E5%B0%9A%E4%B8%AD%E9%BB%91%E7%AE%80%E4%BD%93%2C%E6%A5%B7%E4%BD%93%2C%E9%9A%B6%E4%B9%A6%2C%E9%BB%91%E4%BD%93%22%2C%22screenInfo%22%3A%221440*900*24%22%2C%22plugins%22%3A%22Shockwave%20Flash%2016.0%20r0%3A%3Apepflashplayer.dll%3A%3AShockwave%20Flash%7CThis%20plugin%20allows%20you%20to%20securely%20access%20other%20computers%20that%20have%20been%20shared%20with%20you.%20To%20use%20this%20plugin%20you%20must%20first%20install%20the%20%3Ca%20href%3D%5C%22https%3A%2F%2Fchrome.google.com%2Fremotedesktop%5C%22%3EChrome%20Remote%20Desktop%3C%2Fa%3E%20webapp.%3A%3Ainternal-remoting-viewer%3A%3AChrome%20Remote%20Desktop%20Viewer%7C%3A%3Ainternal-nacl-plugin%3A%3ANative%20Client%7C%3A%3Apdf.dll%3A%3AChrome%20PDF%20Viewer%7CnpCCBEnckey.dll%3A%3AnpCCBEnckey.dll%3A%3ACCBEnckey%20plugin%7CnpCCBInfoScan.dll%3A%3AnpCCBInfoScan.dll%3A%3ACCBInfoScan%20plugin%7CnpCCBNetSignCom.dll%3A%3AnpCCBNetSignCom.dll%3A%3ACCBNetSignCom%20plugin%7CHDZB%20CCB%20USBKEY-2G%20Cert%20Control%20For%20Firefox%3A%3AnpHDZB2gCertCtrl.dll%3A%3Ahd2gccbcertctrl%20plugin%7CHDZB%20CCB%20USBKEY-2G%20SN%20Control%20For%20Firefox%3A%3AnpHDZB2gSNCtrl.dll%3A%3Ahd2gccbsnctrl%20plugin%7C%E5%BB%BA%E8%A1%8C%E7%BD%91%E9%93%B6%E7%9B%BE%E8%AF%81%E4%B9%A6%E6%8E%A7%E4%BB%B6Firefox%E7%89%88%E6%9C%AC%3A%3AnpHDZBCertCtrl.dll%3A%3AHDZBCertCtrl.dll%20plugin%7C%E5%BB%BA%E8%A1%8C%E7%BD%91%E9%93%B6%E7%9B%BE%E5%BA%8F%E5%88%97%E5%8F%B7%E6%8E%A7%E4%BB%B6Firefox%E7%89%88%E6%9C%AC%3A%3AnpHDZBSNCtrl.dll%3A%3AHDZBSNCtrl%20plugin%7CWatchdata%20USBKey%20API%20for%20FireFox3.0%3A%3AnpWDImportCertCtrl.dll%3A%3AWatchdata%20(Beijing)%20Limited%20npwdkctrl%7Cnpdmccbplugin.dll%3A%3Anpdmccbplugin.dll%3A%3Anpdmccbplugin%7Cnpdmccbplugin.dll%3A%3Anpdmwritecert.dll%3A%3Anpdmccbplugin%7CWatchdata%20USBKey%20API%20for%20FireFox3.0%3A%3Anpwdkctrl.dll%3A%3AWatchdata%20(Beijing)%20Limited%20npwdkctrl%7CTencent%20QQ%20CPHelper%20plugin%20for%20Chrome%3A%3Anpactivex.dll%3A%3ATencent%20QQ%7CTencent%20Open%20Platform%20Browser%20Plugin%3A%3AnpQPMWebGamePlugin.dll%3A%3A%E8%85%BE%E8%AE%AF%E5%BC%80%E6%94%BE%E5%B9%B3%E5%8F%B0%E6%B5%8F%E8%A7%88%E5%99%A8%E6%8F%92%E4%BB%B6%7CQQMiniDL%20Plugin%3A%3AnpXFMiniDLPlugin.dll%3A%3AQQMiniDL%20Plugin%7CQQPhoneManager%20Onekey-Install%20plug-in%20for%20Android%20Phones%3A%3AnpQQPhoneManagerExt.dll%3A%3A%E5%BA%94%E7%94%A8%E5%AE%9D%E4%B8%80%E9%94%AE%E5%AE%89%E8%A3%85%E6%8F%92%E4%BB%B6%7CQQ%20QuickLogin%20Helper%3A%3AnpSSOAxCtrlForPTLogin.dll%3A%3ATencent%20SSO%20Platform%7CGoogle%20Update%3A%3AnpGoogleUpdate3.dll%3A%3AGoogle%20Update%7CNPRuntime%20Script%20Plug-in%20Library%20for%20Java(TM)%20Deploy%3A%3AnpDeployJava1.dll%3A%3AJava%20Deployment%20Toolkit%208.0.450.14%7CNext%20Generation%20Java%20Plug-in%2011.45.2%20for%20Mozilla%20browsers%3A%3Anpjp2.dll%3A%3AJava(TM)%20Platform%20SE%208%20U45%7CKingsoft%20Chrome%20WebShield%3A%3Anpkws.dll%3A%3AKingsoft%20Internet%20Security%7C5.1.40728.0%3A%3Anpctrl.dll%3A%3ASilverlight%20Plug-In%7CQQMail%20plugin%20for%20WebKit%20%231.0.0.22%3A%3AnpQQMailWebKit.dll%3A%3AQQMail%20Plugin%7CTencent%20FTN%20plug-in%3A%3AnptxftnWebKit.dll%3A%3ATencent%20FTN%20plug-in%7CQQMusic%3A%3AnpQzoneMusic.dll%3A%3AQQMusic%7CnpQQPhotoDrawEx%20Module%3A%3AnpQQPhotoDrawEx.dll%3A%3AnpQQPhotoDrawEx%7CAlipay%20Security%20Control%3A%3AnpAliSecCtrl.dll%3A%3AAlipay%20Security%20Control%203%7CAlipay%20Internet%20Health%20Control%3A%3AnpAlipaydhc.dll%3A%3AAlipay%20Security%20Payment%20Client%20Suit%7Cnpalicdo%3A%3Anpalicdo.dll%3A%3Anpalicdo%20plugin%7Cnpalidcp%3A%3Anpalidcp.dll%3A%3AAlipay%20webmod%20control%7Cnpaliedit%3A%3Anpaliedit.dll%3A%3AAlipay%20security%20control%7CNCSOFT%20Login%20Launcher%20Module%3A%3Anpncllm3.dll%3A%3ANCSOFT%20Login%20Launcher%20Module%7CQQWebGamePlugin%20Pro%3A%3Anpqqwebgame.dll%3A%3AQQGamePlugin%20Pro%7CShockwave%20Flash%2019.0%20r0%3A%3ANPSWF32_19_0_0_185.dll%3A%3AShockwave%20Flash%7CiTrusPTA%26XEnroll%20hwPTA%2CIEnroll%2CUKeyInstalls%20for%20FireFox%2Cversion%3D1.0.0.2%3A%3ANPComBrg701.dll%3A%3AiTrusChina%20iTrusPTA%2CXEnroll%2CiEnroll%2ChwPTA%2CUKeyInstalls%20Firefox%20Plugin%7CTouchEn%20Key%20for%20Multi-Browser%3A%3AnpKeyPro.dll%3A%3ATouchEn%20Key%20for%20Multi-Browser%7CPowerEnter%20Plug-in%20for%20ABC%3A%3Anppowerenter-abc.dll%3A%3APowerEnter%20Plug-in%20for%20ABC%7Cnpsyunew3%3A%3Anpsyunew3.DLL%3A%3Anpsyunew3%7CnpAliSSOLogin%20Plugin%3A%3AnpAliSSOLogin.dll%3A%3AAliSSOLogin%20plugin%7Cnpwangwang%3A%3Anpwangwang.dll%3A%3AAliWangWang%20Plug-In%20For%20Firefox%20and%20Netscape%7CYunWebDetect%3A%3AnpYunWebDetect.dll%3A%3ABaiduYunGuanjia%20Application%7CQQPCMgr%20Mozilla%20Extenstion%3A%3AnpQMExtensionsMozilla.dll%3A%3AQQPCMgr%20Detector%7CiTunes%20Detector%20Plug-in%3A%3Anpitunes.dll%3A%3AiTunes%20Application%20Detector%7CBaofeng%20Web%20Browser%20plugin%3A%3AnpBFWebBrowserPlugin.dll%3A%3ABaofeng%20StormPlayer%20WebBrowser%20Plugin%7CWeb%20player%20NPPlugin%3A%3AnpWebStrom.dll%3A%3ABaofeng%20StormPlayer%205%7CFirebreath%20ActiveX%20Wrapper%20Example%3A%3AnpQzone6.dll%3A%3AQzone6Wrapper%22%7D",
                    Cookie = Cookies
                };
                result = http.GetHtml(item);
                Cookies = Utilities.MergerCookies(Cookies, result.Cookie);
                retCode = result.Html;
                string tid = Utilities.GetMidStr(retCode.Replace("\\", ""), "tid\":\"", "\",", true);
                string c = Utilities.GetMidStr(retCode, "confidence\":", "}");
                if (c.Length < 3) c = c.PadLeft(3 - c.Length, '0');
                #endregion

                #region 第三步
                //http://passport.weibo.com/visitor/visitor?a=incarnate&t=NKGn0UI44yekXn3TMgWPXKJO%2F30LjzZYGGdYaFmC3%2B4%3D&w=2&c=095&gc=&cb=cross_domain&from=weibo&_rand=0.5244249070528895
                item = new HttpItem()
                {
                    URL = "http://passport.weibo.com/visitor/visitor?a=incarnate&t=" + tid +
                    "&w=2&c=" + c + "&gc=&cb=cross_domain&from=weibo&_rand=0.39206858281977475",
                    Method = "GET",
                    Accept = "*/*",
                    Referer = referer,
                    Cookie = Cookies
                };
                item.Header.Add("Accept-Language", "zh-CN,zh");
                result = http.GetHtml(item);
                Cookies = Utilities.MergerCookies(Cookies, result.Cookie);
                retCode = result.Html;
                string sub = Utilities.GetMidStr(retCode, "sub\":\"", "\"");
                string subp = Utilities.GetMidStr(retCode, "subp\":\"", "\"");
                #endregion

                #region 第四步
                //http://login.sina.com.cn/visitor/visitor?a=crossdomain&cb=return_back&s=_2AkMhQYfof8NjqwJRmPoTzGLna4t2yAjEiebDAHzsJxJjHiA67JnI2xi_dS_1CnBEUWGqAXatU2VW&sp=0033WrSXqPxfM72-Ws9jqgMF55z29P9D9W5wENvW-IBw5J8weojq045x&from=weibo&_rand=0.2508328694384545
                item = new HttpItem()
                {
                    URL = "http://login.sina.com.cn/visitor/visitor?a=crossdomain&cb=return_back&s=" + sub + "&sp=" + subp + "&from=weibo&_rand=0.139822147320956",
                    Method = "GET",
                    Accept = "*/*",
                    Referer = referer,
                    Cookie = Cookies
                };
                item.Header.Add("Accept-Language", "zh-CN,zh");
                result = http.GetHtml(item);
                Cookies = Utilities.MergerCookies(Cookies, result.Cookie);
                retCode = result.Html;
                #endregion

                #region 第五步
                //http://weibo.com/ajaxlogin.php?entry=taobao&action=4&url=https%3A%2F%2Flogin.taobao.com%2Faso%2Ftvs%3Fdomain%3Dweibo%26sid%3D226cb1df7364b2d1f299d2da5fdf0aa4%26target%3D&framelogin=1&callback=parent.sinaSSOController.feedBackUrlCallBack&sudaref=weibo.com&retcode=4049&reason=%CE%AA%C1%CB%C4%FA%B5%C4%D5%CA%BA%C5%B0%B2%C8%AB%A3%AC%C7%EB%CA%E4%C8%EB%D1%E9%D6%A4%C2%EB
                item = new HttpItem()
                {
                    URL = "http://weibo.com/ajaxlogin.php?entry=taobao&action=4&url=https%3A%2F%2Flogin.taobao.com%2Faso%2Ftvs%3Fdomain%3Dweibo%26sid%3D" + sid +
                    "%26target%3D&framelogin=1&callback=parent.sinaSSOController.feedBackUrlCallBack&sudaref=weibo.com&retcode=4049&reason=%CE%AA%C1%CB%C4%FA%B5%C4%D5%CA%BA%C5%B0%B2%C8%AB%A3%AC%C7%EB%CA%E4%C8%EB%D1%E9%D6%A4%C2%EB",
                    Method = "GET",
                    Accept = "text/html,application/xhtml+xml,application/xml,image/webp,*/*",
                    Referer = referer,
                    Cookie = Cookies
                };
                item.Header.Add("Accept-Language", "zh-CN,zh");
                result = http.GetHtml(item);
                Cookies = Utilities.MergerCookies(Cookies, result.Cookie);
                retCode = result.Html;
                #endregion

                #region 获取微博验证码
                item = new HttpItem()
                {
                    URL = "http://login.sina.com.cn/cgi/pin.php?r=" + GetRandom() + "&s=0&p=" + pcid,
                    Method = "GET",
                    Accept = "image/webp,image/*,*/*",
                    Referer = url,
                    ResultType = ResultType.Byte,
                    Cookie = Cookies
                };
                item.Header.Add("Accept-Language", "zh-CN,zh");
                result = http.GetHtml(item);
                Cookies = Utilities.MergerCookies(Cookies, result.Cookie);
                pictureBox1.Image = Utilities.ImageFromByte(result.ResultByte);
                while (txtVerCode.Text.Length != 5)
                {
                    Application.DoEvents();
                }
                VCode = txtVerCode.Text;
                txtVerCode.Text = "";
                #endregion

                #region 有验证码登录
                servertime = Utilities.GetTime().Substring(0, 10);  //重新生成
                nonce = getnonce();                                 //重新生成
                sp = SinaEncrypt(servertime, nonce, wbPass);
                item = new HttpItem()
                {
                    URL = "http://login.sina.com.cn/sso/login.php?client=ssologin.js(v1.4.18)",
                    Method = "POST",
                    Accept = "text/html,application/xhtml+xml,application/xml,image/webp,*/*",
                    Referer = "http://weibo.com/ajaxlogin.php?entry=taobao&action=4&url=https%3A%2F%2Flogin.taobao.com%2Faso%2Ftvs%3Fdomain%3Dweibo%26sid%3D" + sid + "%26target%3D&framelogin=1&callback=parent.sinaSSOController.feedBackUrlCallBack",
                    Cookie = Cookies,
                    Postdata = "entry=weibo&gateway=1&from=&savestate=0&useticket=1&pagerefer=&pcid=" + pcid + "&door=" + VCode +
                    "&vsnf=1&su=" + su + "&service=miniblog&servertime=" + servertime + "&nonce=" + nonce +
                    "&pwencode=rsa2&rsakv=" + rsakv + "&sp=" + sp + "&sr=1600*900&encoding=UTF-8&prelt=82&url=http%3A%2F%2Fweibo.com%2Fajaxlogin.php%3Fentry%3Dtaobao%26action%3D4%26url%3Dhttps%253A%252F%252Flogin.taobao.com%252Faso%252Ftvs%253Fdomain%253Dweibo%2526sid%253D" + sid + "%2526target%253D%26framelogin%3D1%26callback%3Dparent.sinaSSOController.feedBackUrlCallBack&returntype=META"
                };
                result = http.GetHtml(item);
                Cookies = Utilities.MergerCookies(Cookies, result.Cookie);
                retCode = result.Html;
                #endregion
            }
            url = Utilities.GetMidStr(retCode, "location.replace('", "'");
            #endregion

            #region 三次GET请求
            string[] arrUrl = Utilities.GetMidStr(retCode, "arrURL\":[\"", "\"]}").Replace("\\", "").Split(new string[] { "\",\"" }, StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < arrUrl.Length; i++)
            {
                arrUrl[i] += "&callback=sinaSSOController.doCrossDomainCallBack&scriptId=ssoscript" + i.ToString() + "&client=ssologin.js(v1.4.18)&_=" + Utilities.GetTime();
                item = new HttpItem()
                {
                    URL = arrUrl[i],
                    Method = "GET",
                    Accept = "*/*",
                    Referer = "https://login.sina.com.cn/sso/login.php?client=ssologin.js(v1.4.18)",
                };
                result = http.GetHtml(item);
                retCode = result.Html;
            }
            #endregion

            #region 跳转1次
            item = new HttpItem()
            {
                URL = url,
                Method = "GET",
                Accept = "text/html,application/xhtml+xml,application/xml,image/webp,*/*",
                Referer = "https://login.sina.com.cn/sso/login.php?client=ssologin.js(v1.4.18)",
                //Cookie = Cookies
            };
            result = http.GetHtml(item);
            Cookies = Utilities.MergerCookies("", result.Cookie);
            retCode = result.Html;
            url = Utilities.GetMidStr(retCode, "redirect\":\"", "\"").Replace("\\", "");//.Replace("sid=&", "sid=" + sid + "&");
            #endregion

            #region 跳转3次
            item = new HttpItem()
            {
                URL = url,
                Method = "GET",
                Accept = "text/html,application/xhtml+xml,application/xml,image/webp,*/*",
                Referer = "https://login.sina.com.cn/sso/login.php?client=ssologin.js(v1.4.18)",
                Cookie = FirstCookies + ";" + Cookies
            };
            result = http.GetHtml(item);
            Cookies = Utilities.MergerCookies(Cookies, result.Cookie);
            string last = result.LastJumpUrl;//https://reg.taobao.com/member/sina/sina_activation.htm
            retCode = result.Html;
            if (last.Contains("ac/pc_r_open.htm?fromSite=0") || last.EndsWith("www.taobao.com/"))
            {
                MessageBox.Show("已注册号");
                txtwbEmail.Text = "";
                txtwbPass.Text = "";
                txtwbEmail.Focus();
                button1.Enabled = true;
                return;
            }
            #endregion

            #region 获取注册的验证码
            string picUrl = "https:" + Utilities.GetMidStr(retCode, "checkcode\" data-imgurl=\"", "\"").Replace("&amp;", "&");
            string seccionid = Utilities.GetMidStr(picUrl + ";", "sessionid=", ";");
            GetRegisterCode(picUrl);
            #endregion

            #region 检查用户名
        CheckNickAgain:
            item = new HttpItem()
            {
                URL = "https://reg.taobao.com/member/check_nick.do?_input_charset=utf-8",
                Method = "POST",
                Accept = "application/json, text/javascript, */*",
                Referer = "https://reg.taobao.com/member/sina/sina_activation.htm",
                Postdata = "nick=" + Utilities.UTF8(tbNick),
                Cookie = FirstCookies
            };
            item.Header.Add("X-Requested-With", "XMLHttpRequest");
            result = http.GetHtml(item);
            FirstCookies = Utilities.MergerCookies(FirstCookies, result.Cookie);
            retCode = result.Html;//{"success":true}
            //{"success":false,"reason":"ERROR_DUP_NICK_NAME","commandNick":["深秋爱更浓24469229","深秋爱更浓144901239","深秋爱更浓559961334"]}
            if (!retCode.Contains("{\"success\":true}"))
            {
                string[] rdNick = Utilities.GetMidStr(retCode, "commandNick\":[\"", "\"]").Split(new string[] { "\",\"" }, StringSplitOptions.RemoveEmptyEntries);
                Random r = new Random();
                tbNick = rdNick[r.Next(rdNick.Length)];
                txttbNick.Text = tbNick;//新昵称
                goto CheckNickAgain;
            }
            #endregion

            #region 检查验证码
        CheckCodeAgain:
            while (txtVerCode.Text.Length != 4)
            {
                Application.DoEvents();
            }
            VCode = txtVerCode.Text;
            item = new HttpItem()//检查验证码,出错怎么办？
            {
                URL = "https://pin.aliyun.com/check_img?code=" + VCode + "&_ksTS=" + Utilities.GetTime() +
                "_141&callback=jsonp142&identity=member1.taobao.com&sessionid=" + seccionid + "&delflag=0&isg2=An9%2FAQXbznG73UeqAXzdxO8mT10JXtMB",
                Method = "GET",
                Accept = "*/*",
                Referer = "https://reg.taobao.com/member/sina/sina_activation.htm"
            };
            result = http.GetHtml(item);
            retCode = result.Html;//jsonp142({"message":"SUCCESS.","refresh":"false"})
            if (!retCode.Contains("message\":\"SUCCESS."))//jsonp142({"message":"ERROR.","refresh":"true"})验证码错误
            {
                txtVerCode.Text = "";
                GetRegisterCode(picUrl);
                txtVerCode.Focus();
                goto CheckCodeAgain;
            }
            #endregion

            #region 检查手机号
        GetPhongAgain:
            item = new HttpItem()
            {
                URL = "https://reg.taobao.com/member/new_email_check_cellphone.do",
                Method = "POST",
                Accept = "application/json, text/javascript, */*",
                Referer = "https://reg.taobao.com/member/sina/sina_activation.htm",
                Postdata = "userId&mobile_area=1&mobile=" + mobile,
                Cookie = FirstCookies
            };
            item.Header.Add("Origin", "https://reg.taobao.com");
            item.Header.Add("X-Requested-With", "XMLHttpRequest");
            result = http.GetHtml(item);
            Cookies = Utilities.MergerCookies("", result.Cookie);
            retCode = result.Html;//{"success":true,"alipay":true,"url":null}
            if (!retCode.Contains("success\":true,\"alipay\":true"))//手机不可用
            {
                txtmobile.Text = "";
                txtmobile.Focus();
                while (txtmobile.Text.Length != 11)
                {
                    Application.DoEvents();
                }
                mobile = txtmobile.Text;
                goto GetPhongAgain;
            }
            #endregion

            #region 确定,发送手机
        SendAgain:
            mobile = "13640954881";
            ChangeMobile = false;
            item = new HttpItem()
            {
                URL = "https://reg.taobao.com/member/checkcode/send_cell_checkcode.do?type=SinaBusinessActivation",
                Method = "POST",
                Accept = "application/json, text/javascript, */*",
                Referer = "https://reg.taobao.com/member/sina/sina_activation.htm",
                Postdata = "alipay=&mobile=" + mobile + "&mobilePhone=&mobile_area=1&userNumId",
                Cookie = FirstCookies
            };
            item.Header.Add("X-Requested-With", "XMLHttpRequest");
            result = http.GetHtml(item);
            retCode = result.Html;//{"next":"","success":true}
            if (retCode.Contains("ERROR_MOBILE_IN_BLACK"))
            {
                MessageBox.Show("手机进入黑名单!");
                txtmobile.Text = "";
                txtmobile.Focus();
                while (txtmobile.Text.Length != 11)
                {
                    if (ChangeMobile) goto SendAgain;//更换手机号
                    Application.DoEvents();
                }
                mobile = txtmobile.Text;
                goto SendAgain;
            }
            else if (!retCode.Contains("next\":\"\",\"success"))
            {
                MessageBox.Show("发送失败,重新再试一次.");
                goto SendAgain;
            }
            #endregion
            //Thread.Sleep(1500);
            #region 输入安全码,获取UA
            txtmobileCode.Focus();
            while (txtmobileCode.Text.Length != 6)
            {
                Application.DoEvents();
            }
            mobileCode = txtmobileCode.Text;
            txtmobileCode.Text = "";
        GetUaAgain:
            item = new HttpItem()//检查验证码
            {
                URL = "http://s.coderdn.com/get/?key=7QXZ42N9XCK7XWXC&type=weiboopentaobao&userNick=" + tbNick + "&code=" + VCode + "&sid=" + sid + "&spm=" + spm + "&sc=" +
                Utilities.MD5(tbNick + "Jkfr673FhWQkdfM8").ToLower(),
                Method = "GET"
            };
            result = http.GetHtml(item);
            string ua = result.Html;
            if (ua.Length < 200)
            {
                MessageBox.Show("UA出错:" + ua);
                goto GetUaAgain;
            }
            #endregion

            #region 开始注册
            item = new HttpItem()
            {
                URL = "https://reg.taobao.com/member/sina/sina_activation_action.do?_input_charset=utf-8",
                Method = "POST",
                Accept = "application/json, text/javascript, */*",
                Referer = "https://reg.taobao.com/member/sina/sina_activation.htm",
                Postdata = "nick=" + Utilities.UTF8(tbNick) + "&pwd=" + tbPass + "&rePwd=" + tbPass + "&imgChkcode=" + VCode +
                "&mobile=" + mobile + "&mobile_area=1&code=" + mobileCode + "&userId&accountType&sign&ua=" + ua + "&CtrlVersion&tid",
                Cookie = FirstCookies
            };
            item.Header.Add("X-Requested-With", "XMLHttpRequest");
            result = http.GetHtml(item);
            retCode = result.Html;
            string uid = Utilities.GetMidStr(retCode, "html?uid\\u003d", "\\");
            item = new HttpItem()//检查验证码
            {
                URL = "https://reg.taobao.com/member/register_confirm.jhtml?uid=" + uid + "&nk=" + Utilities.UTF8(tbNick) + "&css_style=taobao&from=SinaBusinessActivation",
                Method = "GET",
                Accept = "*/*",
                Cookie = FirstCookies
            };
            result = http.GetHtml(item);
            retCode = result.Html;//恭喜亲注册成功！
            url = Utilities.GetMidStr(retCode, "document.location = \"", "\"");
            //FirstCookies = Utilities.MergerCookies(FirstCookies, result.Cookie);
            item = new HttpItem()//检查验证码
            {
                URL = url,
                Method = "GET",
                Accept = "image/jpeg, application/x-ms-application, image/gif, application/xaml+xml, image/pjpeg, application/x-ms-xbap, */*",
                Cookie = FirstCookies
            };
            result = http.GetHtml(item);
            retCode = result.Html;//恭喜亲注册成功！
            if (retCode.Contains("恭喜亲注册成功！"))
            {
                outRegisterInfo(wbEmail + "|" + wbPass + "\t" + tbNick + "|" + tbPass);
                MessageBox.Show("注册成功:[" + tbNick + "|" + tbPass + "]");
            }
            else MessageBox.Show("注册失败!");
            button1.Enabled = true;
            #endregion
        }
        #endregion

        #region 功能模块
        #region 写出注册信息
        void outRegisterInfo(string info)
        {
            DateTime dt = DateTime.Now;
            using (StreamWriter sw = File.AppendText("注册结果.txt"))
            {
                sw.WriteLine(info + "|注册时间:" + dt.ToString("yyyy-MM-dd HH:mm:ss"));
                sw.Close();
            }
        }
        #endregion

        #region 获取注册验证码
        private void GetRegisterCode(string PicUrl)
        {
            item = new HttpItem()
            {
                URL = PicUrl + "&kjtype=default&t=" + Utilities.GetTime(),
                Method = "GET",
                Accept = "image/webp,image/*,*/*",
                Referer = "https://reg.taobao.com/member/sina/sina_activation.htm",
                ResultType = ResultType.Byte,
                Cookie = Cookies
            };
            item.Header.Add("Accept-Language", "zh-CN,zh");
            result = http.GetHtml(item);
            pictureBox1.Image = Utilities.ImageFromByte(result.ResultByte);
        }
        #endregion

        #region spm
        private string GetSPM()//按指定类型更改变量的定义
        {
            string MyJs = "function GetSPM(){var a=\"\",o=\"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\",n=!1;for(;a.length<6;){var i=o.substr(Math.floor(62*" +
            "Math.random()),1);!n&&a.length<=2&&(\"g\"==i.toLowerCase()||\"l\"==i.toLowerCase())&&(0==a.length&&\"g\"==i.toLowerCase()?Math.random()<.5&&(i=e(1),n=" +
            "!0):1==a.length&&\"l\"==i.toLowerCase()&&\"g\"==a.charAt(0).toLowerCase()&&(i=e(2),n=!0)),a+=i}return a}";
            Type obj = Type.GetTypeFromProgID("ScriptControl");
            object ScriptControl = Activator.CreateInstance(obj);
            obj.InvokeMember("Language", BindingFlags.SetProperty, null, ScriptControl, new object[] { "JScript" });
            obj.InvokeMember("AddCode", BindingFlags.InvokeMethod, null, ScriptControl, new object[] { MyJs });
            string result = obj.InvokeMember("Eval", BindingFlags.InvokeMethod, null, ScriptControl, new object[] { "GetSPM()" }).ToString();
            return result;
        }
        #endregion

        #region cache
        private string makeCacheNum()//按指定类型更改变量的定义
        {
            string MyJs = "function makeCacheNum(){return Math.floor(268435456*Math.random()).toString(16)}";
            Type obj = Type.GetTypeFromProgID("ScriptControl");
            object ScriptControl = Activator.CreateInstance(obj);
            obj.InvokeMember("Language", BindingFlags.SetProperty, null, ScriptControl, new object[] { "JScript" });
            obj.InvokeMember("AddCode", BindingFlags.InvokeMethod, null, ScriptControl, new object[] { MyJs });
            string result = obj.InvokeMember("Eval", BindingFlags.InvokeMethod, null, ScriptControl, new object[] { "makeCacheNum()" }).ToString();
            return result;
        }
        #endregion

        #region 取随机数值
        private string GetRandom()
        {
            Random rd = new Random();
            return (rd.Next() * 100000000).ToString();
        }
        #endregion

        #region 密码加密
        private string SinaEncrypt(string servertime, string nonce, string Pass)//按指定类型更改变量的定义
        {
            string MyJs = "function SinaEncrypt(servertime,nonce,Pass){var key=\"EB2A38568661887FA180BDDB5CABD5F21C7BFD59C090CB2D245A87AC253062882729293E5506350508E7F9AA3BB77F43" +
            "33231490F915F6D63C55FE2F08A49B353F444AD3993CACC02DB784ABBB8E42A9B1BBFFFB38BE18D78E87A0E41B9B8F73A928EE0CCEE1F6739884B9777E4FE9E88A1BBE495927AC4A799B31" +
            "81D6442443\";var b=new RSAKey;b.setPublic(key,\"10001\");return b.encrypt([servertime,nonce].join(\"\\t\")+\"\\n\"+encodeURIComponent(Pass))}function RS" +
            "AKey(){this.n=null;this.e=0;this.d=null;this.p=null;this.q=null;this.dmp1=null;this.dmq1=null;this.coeff=null}function s(z,t){this.n=k(z,16);this.e=pa" +
            "rseInt(t,16)}function aa(t){return t.modPowInt(this.e,this.n)}function u(aE){var t=aj(aE,(this.n.bitLength()+7)>>3);if(t==null){return null}var aF=thi" +
            "s.doPublic(t);if(aF==null){return null}var z=aF.toString(16);if((z.length&1)==0){return z}else{return\"0\"+z}}RSAKey.prototype.doPublic=aa;RSAKey.prot" +
            "otype.setPublic=s;RSAKey.prototype.encrypt=u;function aw(z,t,aE){if(z!=null){if(\"number\"==typeof z){this.fromNumber(z,t,aE)}else{if(t==null&&\"strin" +
            "g\"!=typeof z){this.fromString(z,256)}else{this.fromString(z,t)}}}}function l(){return new aw(null)}function b(aG,t,z,aF,aI,aH){while(--aH>=0){var aE=" +
            "t*this[aG++]+z[aF]+aI;aI=Math.floor(aE/67108864);z[aF++]=aE&67108863}return aI}function aC(aG,aL,aM,aF,aJ,t){var aI=aL&32767,aK=aL>>15;while(--t>=0){v" +
            "ar aE=this[aG]&32767;var aH=this[aG++]>>15;var z=aK*aE+aH*aI;aE=aI*aE+((z&32767)<<15)+aM[aF]+(aJ&1073741823);aJ=(aE>>>30)+(z>>>15)+aK*aH+(aJ>>>30);aM[" +
            "aF++]=aE&1073741823}return aJ}function aB(aG,aL,aM,aF,aJ,t){var aI=aL&16383,aK=aL>>14;while(--t>=0){var aE=this[aG]&16383;var aH=this[aG++]>>14;var z=" +
            "aK*aE+aH*aI;aE=aI*aE+((z&16383)<<14)+aM[aF]+aJ;aJ=(aE>>28)+(z>>14)+aK*aH;aM[aF++]=aE&268435455}return aJ}var aA=30;aw.prototype.am=aC;aw.prototype.DB=" +
            "aA;aw.prototype.DM=((1<<aA)-1);aw.prototype.DV=(1<<aA);var ae=52;aw.prototype.FV=Math.pow(2,ae);aw.prototype.F1=ae-aA;aw.prototype.F2=2*aA-ae;var ai=\"" +
            "0123456789abcdefghijklmnopqrstuvwxyz\";var ak=new Array();var au,A;au=\"0\".charCodeAt(0);for(A=0;A<=9;++A){ak[au++]=A}au=\"a\".charCodeAt(0);for(A=1" +
            "0;A<36;++A){ak[au++]=A}au=\"A\".charCodeAt(0);for(A=10;A<36;++A){ak[au++]=A}function aD(t){return ai.charAt(t)}function E(z,t){var aE=ak[z.charCodeAt(" +
            "t)];return(aE==null)?-1:aE}function ac(z){for(var t=this.t-1;t>=0;--t){z[t]=this[t]}z.t=this.t;z.s=this.s}function r(t){this.t=1;this.s=(t<0)?-1:0;if(" +
            "t>0){this[0]=t}else{if(t<-1){this[0]=t+DV}else{this.t=0}}}function f(t){var z=l();z.fromInt(t);return z}function B(aI,z){var aF;if(z==16){aF=4}else{if" +
            "(z==8){aF=3}else{if(z==256){aF=8}else{if(z==2){aF=1}else{if(z==32){aF=5}else{if(z==4){aF=2}else{this.fromRadix(aI,z);return}}}}}}this.t=0;this.s=0;var" +
            " aH=aI.length,aE=false,aG=0;while(--aH>=0){var t=(aF==8)?aI[aH]&255:E(aI,aH);if(t<0){if(aI.charAt(aH)==\"-\"){aE=true}continue}aE=false;if(aG==0){this" +
            "[this.t++]=t}else{if(aG+aF>this.DB){this[this.t-1]|=(t&((1<<(this.DB-aG))-1))<<aG;this[this.t++]=(t>>(this.DB-aG))}else{this[this.t-1]|=t<<aG}}aG+=aF;" +
            "if(aG>=this.DB){aG-=this.DB}}if(aF==8&&(aI[0]&128)!=0){this.s=-1;if(aG>0){this[this.t-1]|=((1<<(this.DB-aG))-1)<<aG}}this.clamp();if(aE){aw.ZERO.subTo" +
            "(this,this)}}function T(){var t=this.s&this.DM;while(this.t>0&&this[this.t-1]==t){--this.t}}function v(z){if(this.s<0){return\"-\"+this.negate().toStr" +
            "ing(z)}var aE;if(z==16){aE=4}else{if(z==8){aE=3}else{if(z==2){aE=1}else{if(z==32){aE=5}else{if(z==4){aE=2}else{return this.toRadix(z)}}}}}var aG=(1<<a" +
            "E)-1,aJ,t=false,aH=\"\",aF=this.t;var aI=this.DB-(aF*this.DB)%aE;if(aF-->0){if(aI<this.DB&&(aJ=this[aF]>>aI)>0){t=true;aH=aD(aJ)}while(aF>=0){if(aI<aE" +
            "){aJ=(this[aF]&((1<<aI)-1))<<(aE-aI);aJ|=this[--aF]>>(aI+=this.DB-aE)}else{aJ=(this[aF]>>(aI-=aE))&aG;if(aI<=0){aI+=this.DB;--aF}}if(aJ>0){t=true}if(t" +
            "){aH+=aD(aJ)}}}return t?aH:\"0\"}function W(){var t=l();aw.ZERO.subTo(this,t);return t}function ap(){return(this.s<0)?this.negate():this}function K(t)" +
            "{var aE=this.s-t.s;if(aE!=0){return aE}var z=this.t;aE=z-t.t;if(aE!=0){return aE}while(--z>=0){if((aE=this[z]-t[z])!=0){return aE}}return 0}function n" +
            "(z){var aF=1,aE;if((aE=z>>>16)!=0){z=aE;aF+=16}if((aE=z>>8)!=0){z=aE;aF+=8}if((aE=z>>4)!=0){z=aE;aF+=4}if((aE=z>>2)!=0){z=aE;aF+=2}if((aE=z>>1)!=0){z=" +
            "aE;aF+=1}return aF}function y(){if(this.t<=0){return 0}return this.DB*(this.t-1)+n(this[this.t-1]^(this.s&this.DM))}function av(aE,z){var t;for(t=this" +
            ".t-1;t>=0;--t){z[t+aE]=this[t]}for(t=aE-1;t>=0;--t){z[t]=0}z.t=this.t+aE;z.s=this.s}function ab(aE,z){for(var t=aE;t<this.t;++t){z[t-aE]=this[t]}z.t=M" +
            "ath.max(this.t-aE,0);z.s=this.s}function x(aJ,aF){var z=aJ%this.DB;var t=this.DB-z;var aH=(1<<t)-1;var aG=Math.floor(aJ/this.DB),aI=(this.s<<z)&this.D" +
            "M,aE;for(aE=this.t-1;aE>=0;--aE){aF[aE+aG+1]=(this[aE]>>t)|aI;aI=(this[aE]&aH)<<z}for(aE=aG-1;aE>=0;--aE){aF[aE]=0}aF[aG]=aI;aF.t=this.t+aG+1;aF.s=thi" +
            "s.s;aF.clamp()}function p(aI,aF){aF.s=this.s;var aG=Math.floor(aI/this.DB);if(aG>=this.t){aF.t=0;return}var z=aI%this.DB;var t=this.DB-z;var aH=(1<<z)" +
            "-1;aF[0]=this[aG]>>z;for(var aE=aG+1;aE<this.t;++aE){aF[aE-aG-1]|=(this[aE]&aH)<<t;aF[aE-aG]=this[aE]>>z}if(z>0){aF[this.t-aG-1]|=(this.s&aH)<<t}aF.t=" +
            "this.t-aG;aF.clamp()}function af(z,aF){var aE=0,aG=0,t=Math.min(z.t,this.t);while(aE<t){aG+=this[aE]-z[aE];aF[aE++]=aG&this.DM;aG>>=this.DB}if(z.t<thi" +
            "s.t){aG-=z.s;while(aE<this.t){aG+=this[aE];aF[aE++]=aG&this.DM;aG>>=this.DB}aG+=this.s}else{aG+=this.s;while(aE<z.t){aG-=z[aE];aF[aE++]=aG&this.DM;aG>" +
            ">=this.DB}aG-=z.s}aF.s=(aG<0)?-1:0;if(aG<-1){aF[aE++]=this.DV+aG}else{if(aG>0){aF[aE++]=aG}}aF.t=aE;aF.clamp()}function H(z,aF){var t=this.abs(),aG=z." +
            "abs();var aE=t.t;aF.t=aE+aG.t;while(--aE>=0){aF[aE]=0}for(aE=0;aE<aG.t;++aE){aF[aE+t.t]=t.am(0,aG[aE],aF,aE,0,t.t)}aF.s=0;aF.clamp();if(this.s!=z.s){a" +
            "w.ZERO.subTo(aF,aF)}}function V(aE){var t=this.abs();var z=aE.t=2*t.t;while(--z>=0){aE[z]=0}for(z=0;z<t.t-1;++z){var aF=t.am(z,t[z],aE,2*z,0,1);if((aE" +
            "[z+t.t]+=t.am(z+1,2*t[z],aE,2*z+1,aF,t.t-z-1))>=t.DV){aE[z+t.t]-=t.DV;aE[z+t.t+1]=1}}if(aE.t>0){aE[aE.t-1]+=t.am(z,t[z],aE,2*z,0,1)}aE.s=0;aE.clamp()}" +
            "function I(aM,aJ,aI){var aS=aM.abs();if(aS.t<=0){return}var aK=this.abs();if(aK.t<aS.t){if(aJ!=null){aJ.fromInt(0)}if(aI!=null){this.copyTo(aI)}return" +
            "}if(aI==null){aI=l()}var aG=l(),z=this.s,aL=aM.s;var aR=this.DB-n(aS[aS.t-1]);if(aR>0){aS.lShiftTo(aR,aG);aK.lShiftTo(aR,aI)}else{aS.copyTo(aG);aK.cop" +
            "yTo(aI)}var aO=aG.t;var aE=aG[aO-1];if(aE==0){return}var aN=aE*(1<<this.F1)+((aO>1)?aG[aO-2]>>this.F2:0);var aV=this.FV/aN,aU=(1<<this.F1)/aN,aT=1<<th" +
            "is.F2;var aQ=aI.t,aP=aQ-aO,aH=(aJ==null)?l():aJ;aG.dlShiftTo(aP,aH);if(aI.compareTo(aH)>=0){aI[aI.t++]=1;aI.subTo(aH,aI)}aw.ONE.dlShiftTo(aO,aH);aH.su" +
            "bTo(aG,aG);while(aG.t<aO){aG[aG.t++]=0}while(--aP>=0){var aF=(aI[--aQ]==aE)?this.DM:Math.floor(aI[aQ]*aV+(aI[aQ-1]+aT)*aU);if((aI[aQ]+=aG.am(0,aF,aI,a" +
            "P,0,aO))<aF){aG.dlShiftTo(aP,aH);aI.subTo(aH,aI);while(aI[aQ]<--aF){aI.subTo(aH,aI)}}}if(aJ!=null){aI.drShiftTo(aO,aJ);if(z!=aL){aw.ZERO.subTo(aJ,aJ)}" +
            "}aI.t=aO;aI.clamp();if(aR>0){aI.rShiftTo(aR,aI)}if(z<0){aw.ZERO.subTo(aI,aI)}}function S(t){var z=l();this.abs().divRemTo(t,null,z);if(this.s<0&&z.com" +
            "pareTo(aw.ZERO)>0){t.subTo(z,z)}return z}function O(t){this.m=t}function Z(t){if(t.s<0||t.compareTo(this.m)>=0){return t.mod(this.m)}else{return t}}fu" +
            "nction ao(t){return t}function N(t){t.divRemTo(this.m,null,t)}function L(t,aE,z){t.multiplyTo(aE,z);this.reduce(z)}function ay(t,z){t.squareTo(z);this" +
            ".reduce(z)}O.prototype.convert=Z;O.prototype.revert=ao;O.prototype.reduce=N;O.prototype.mulTo=L;O.prototype.sqrTo=ay;function F(){if(this.t<1){return " +
            "0}var t=this[0];if((t&1)==0){return 0}var z=t&3;z=(z*(2-(t&15)*z))&15;z=(z*(2-(t&255)*z))&255;z=(z*(2-(((t&65535)*z)&65535)))&65535;z=(z*(2-t*z%this.D" +
            "V))%this.DV;return(z>0)?this.DV-z:-z}function j(t){this.m=t;this.mp=t.invDigit();this.mpl=this.mp&32767;this.mph=this.mp>>15;this.um=(1<<(t.DB-15))-1;" +
            "this.mt2=2*t.t}function an(t){var z=l();t.abs().dlShiftTo(this.m.t,z);z.divRemTo(this.m,null,z);if(t.s<0&&z.compareTo(aw.ZERO)>0){this.m.subTo(z,z)}re" +
            "turn z}function ax(t){var z=l();t.copyTo(z);this.reduce(z);return z}function U(t){while(t.t<=this.mt2){t[t.t++]=0}for(var aE=0;aE<this.m.t;++aE){var z" +
            "=t[aE]&32767;var aF=(z*this.mpl+(((z*this.mph+(t[aE]>>15)*this.mpl)&this.um)<<15))&t.DM;z=aE+this.m.t;t[z]+=this.m.am(0,aF,t,aE,0,this.m.t);while(t[z]" +
            ">=t.DV){t[z]-=t.DV;t[++z]++}}t.clamp();t.drShiftTo(this.m.t,t);if(t.compareTo(this.m)>=0){t.subTo(this.m,t)}}function aq(t,z){t.squareTo(z);this.reduc" +
            "e(z)}function D(t,aE,z){t.multiplyTo(aE,z);this.reduce(z)}j.prototype.convert=an;j.prototype.revert=ax;j.prototype.reduce=U;j.prototype.mulTo=D;j.prot" +
            "otype.sqrTo=aq;function m(){return((this.t>0)?(this[0]&1):this.s)==0}function C(aJ,aK){if(aJ>4294967295||aJ<1){return aw.ONE}var aI=l(),aE=l(),aH=aK.c" +
            "onvert(this),aG=n(aJ)-1;aH.copyTo(aI);while(--aG>=0){aK.sqrTo(aI,aE);if((aJ&(1<<aG))>0){aK.mulTo(aE,aH,aI)}else{var aF=aI;aI=aE;aE=aF}}return aK.rever" +
            "t(aI)}function ar(aE,t){var aF;if(aE<256||t.isEven()){aF=new O(t)}else{aF=new j(t)}return this.exp(aE,aF)}aw.prototype.copyTo=ac;aw.prototype.fromInt=" +
            "r;aw.prototype.fromString=B;aw.prototype.clamp=T;aw.prototype.dlShiftTo=av;aw.prototype.drShiftTo=ab;aw.prototype.lShiftTo=x;aw.prototype.rShiftTo=p;a" +
            "w.prototype.subTo=af;aw.prototype.multiplyTo=H;aw.prototype.squareTo=V;aw.prototype.divRemTo=I;aw.prototype.invDigit=F;aw.prototype.isEven=m;aw.protot" +
            "ype.exp=C;aw.prototype.toString=v;aw.prototype.negate=W;aw.prototype.abs=ap;aw.prototype.compareTo=K;aw.prototype.bitLength=y;aw.prototype.mod=S;aw.pr" +
            "ototype.modPowInt=ar;aw.ZERO=f(0);aw.ONE=f(1);function o(){this.i=0;this.j=0;this.S=new Array()}function h(aG){var aF,z,aE;for(aF=0;aF<256;++aF){this." +
            "S[aF]=aF}z=0;for(aF=0;aF<256;++aF){z=(z+this.S[aF]+aG[aF%aG.length])&255;aE=this.S[aF];this.S[aF]=this.S[z];this.S[z]=aE}this.i=0;this.j=0}function a(" +
            "){var z;this.i=(this.i+1)&255;this.j=(this.j+this.S[this.i])&255;z=this.S[this.i];this.S[this.i]=this.S[this.j];this.S[this.j]=z;return this.S[(z+this" +
            ".S[this.i])&255]}o.prototype.init=h;o.prototype.next=a;function at(){return new o()}var R=256;var q;var Y;var ag;function g(t){Y[ag++]^=t&255;Y[ag++]^" +
            "=(t>>8)&255;Y[ag++]^=(t>>16)&255;Y[ag++]^=(t>>24)&255;if(ag>=R){ag-=R}}function X(){g(new Date().getTime())}if(Y==null){Y=new Array();ag=0;var M;while" +
            "(ag<R){M=Math.floor(65536*Math.random());Y[ag++]=M>>>8;Y[ag++]=M&255}ag=0;X()}function G(){if(q==null){X();q=at();q.init(Y);for(ag=0;ag<Y.length;++ag)" +
            "{Y[ag]=0}ag=0}return q.next()}function az(z){var t;for(t=0;t<z.length;++t){z[t]=G()}}function ah(){}ah.prototype.nextBytes=az;function k(z,t){return n" +
            "ew aw(z,t)}function al(aE,aF){var t=\"\";var z=0;while(z+aF<aE.length){t+=aE.substring(z,z+aF)+\"\\n\";z+=aF}return t+aE.substring(z,aE.length)}function" +
            " w(t){if(t<16){return\"0\"+t.toString(16)}else{return t.toString(16)}}function aj(aF,aI){var aH=new Array();var aE=aF.length-1;while(aE>=0&&aI>0){var " +
            "aG=aF.charCodeAt(aE--);if(aG<128){aH[--aI]=aG}else{if((aG>127)&&(aG<2048)){aH[--aI]=(aG&63)|128;aH[--aI]=(aG>>6)|192}else{aH[--aI]=(aG&63)|128;aH[--aI" +
            "]=((aG>>6)&63)|128;aH[--aI]=(aG>>12)|224}}}aH[--aI]=0;var z=new ah();var t=new Array();while(aI>2){t[0]=0;while(t[0]==0){z.nextBytes(t)}aH[--aI]=t[0]}" +
            "aH[--aI]=2;aH[--aI]=0;return new aw(aH)}";
            Type obj = Type.GetTypeFromProgID("ScriptControl");
            object ScriptControl = Activator.CreateInstance(obj);
            obj.InvokeMember("Language", BindingFlags.SetProperty, null, ScriptControl, new object[] { "JScript" });
            obj.InvokeMember("AddCode", BindingFlags.InvokeMethod, null, ScriptControl, new object[] { MyJs });
            string result = obj.InvokeMember("Eval", BindingFlags.InvokeMethod, null, ScriptControl, new object[] { "SinaEncrypt('" + servertime + "','" + nonce + "','" + Pass + "')" }).ToString();
            return result;
        }
        #endregion

        #region 取Nonce
        private string getnonce()
        {
            string MyJs = "function getnonce(){var x=\"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\";var str=\"\";for(var i=0;i<6;i++){str+=x.charAt(Math.ceil(Math.random()*1000000)%x." +
            "length)}return str}";
            Type obj = Type.GetTypeFromProgID("ScriptControl");
            object ScriptControl = Activator.CreateInstance(obj);
            obj.InvokeMember("Language", BindingFlags.SetProperty, null, ScriptControl, new object[] { "JScript" });
            obj.InvokeMember("AddCode", BindingFlags.InvokeMethod, null, ScriptControl, new object[] { MyJs });
            string result = obj.InvokeMember("Eval", BindingFlags.InvokeMethod, null, ScriptControl, new object[] { "getnonce()" }).ToString();
            return result;
        }
        #endregion

        #region 更换手机号
        private void txtmobile_TextChanged(object sender, EventArgs e)
        {
            if (txtmobile.Text != mobile)
            {
                mobile = txtmobile.Text;
                ChangeMobile = true;
            }
        }
        #endregion
        #endregion
    }
}