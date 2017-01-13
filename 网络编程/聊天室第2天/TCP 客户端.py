from socket import *
from time import ctime
import threading
from enum import Enum
import struct

HOST = '127.0.0.1'  # 服务器IP地址
PORT = 1234  # 服务器端口
MESSAGEBUF = 1024 + 8

class EnumMessageType(Enum):
    common      = 1 #普通消息
    reg         = 2 # 注册消息
    login       = 3 # 登录消息
    file        = 4 # 传输文件
    picture     = 5 # 发送图片
    control     = 6 # 远控
    anonymous   = 7 #匿名聊天


def RecvThread(sock):
    try:
        while True:
            message = sock.recv(MESSAGEBUF)
            # 消息类型
            type, = struct.unpack("i", message[ :4 ])
            # 消息长度
            length, = struct.unpack("L", message[ 4:8 ])
            buf, = struct.unpack("%ds" % length, message[ 8:8 + length ])
            message_recv = buf.decode("gb2312")
            print(message_recv)
    except ConnectionResetError as e:
        exit(0)


def InputFun(mysocket, name):
    # 创建线程接收消息
    t = threading.Thread(target=RecvThread, args=(mysocket,))
    t.start();
    # 自循环发送消息
    while True:
        message = input() # 在这输入你的消息
        message = (name+"说："+message).encode("gb2312")
        message_type = EnumMessageType.common
        message_len = len(message)
        message_send = struct.pack("ll%ds"%message_len, message_type.value, message_len, message)
        mysocket.send(message_send)
    mysocket.close()




def Anonymous(mysocket):
    # 告诉服务器我要匿名聊天
    message_type = EnumMessageType.anonymous
    message_len  = 0# 发个消息类型就行，不用发消息
    message = struct.pack("i",message_type.value)
    mysocket.send(message)
    #  等客户端给我分配昵称
    message = mysocket.recv(MESSAGEBUF)
    # 消息类型
    type, = struct.unpack("i", message[ :4 ])
    # 消息长度
    length, = struct.unpack("L", message[ 4:8 ])
    buf, = struct.unpack("%ds" % length, message[ 8:8 + length ])
    name = buf.decode("gb2312")
    print("你的名字：" + name)
    InputFun(mysocket, name)



def Reg(mysocket):
    name = None
    while True:
        # 姓名密码
        name = input("请输入姓名：\n")
        if not str(name).isidentifier():
            continue
        password = input("请输入密码：\n")
        # 构造message
        message_type = EnumMessageType.reg
        name_encode = name.encode("gb2312")
        password_encode = password.encode("gb2312")
        message_len = len(name_encode) + len(password_encode)+4# 比普通消息多4字节
        name_len  = len(name_encode)
        password_len = len(password_encode)
        message = struct.pack("lll%ds%ds"%(name_len,password_len), message_type.value, message_len, name_len,name_encode,password_encode)
        mysocket.send(message);
        # 等待系统确认能否注册
        message = mysocket.recv(MESSAGEBUF)
        # 消息类型
        type, = struct.unpack("i", message[ :4 ])
        # 消息长度
        length, = struct.unpack("L", message[ 4:8 ])
        buf, = struct.unpack("%ds" % length, message[ 8:8 + length ])
        message_recv = buf.decode("gb2312")
        print(message_recv)
        # 注册失败
        if message_recv != "succeed!":
            continue
        # 注册成功
        break
    InputFun(mysocket, name)



def Login(mysocket):
    name = None
    while True:
        # 姓名密码
        name = input("请输入姓名：\n")
        if not str(name).isidentifier():
            continue
        password = input("请输入密码：\n")
        # 构造message
        message_type = EnumMessageType.login
        name_encode = name.encode("gb2312")
        password_encode = password.encode("gb2312")
        message_len = len(name_encode) + len(password_encode) + 4  # 比普通消息多4字节
        name_len = len(name_encode)
        password_len = len(password_encode)
        message = struct.pack("lll%ds%ds" % (name_len, password_len), message_type.value, message_len, name_len,
                              name_encode, password_encode)
        mysocket.send(message);
        # 等待系统确认能否注册
        message = mysocket.recv(MESSAGEBUF)
        # 消息类型
        type, = struct.unpack("i", message[ :4 ])
        # 消息长度
        length, = struct.unpack("L", message[ 4:8 ])
        buf, = struct.unpack("%ds" % length, message[ 8:8 + length ])
        message_recv = buf.decode("gb2312")
        print(message_recv)
        #  登录失败
        if message_recv != "succeed!":
            continue
        # 注册成功
        break
    InputFun(mysocket, name)




def GetFun(sel):
    switcher = {1: Anonymous, 2: Reg, 3: Login}
    return switcher.get(sel,None)


def Menu():
    print("1、匿名聊天")
    print("2、注册")
    print("3、登录")
    switcher = {1: 1, 2: 2, 3: 3}
    while True:
        nRet = int(input("请选择聊天模式！\n"))
        nSel = switcher.get(nRet,None)
        if nSel is not None:
            return nSel


def main():
    ADDR = (HOST, PORT)
    clientSocket = socket(AF_INET,SOCK_STREAM)
    clientSocket.connect(ADDR)
    # 菜单选择
    nSel = Menu()
    # 不同的菜单对应不同的函数调用
    Fun = GetFun(nSel)
    # 调用函数
    Fun(clientSocket)
    input()


if __name__ == '__main__':
    main()