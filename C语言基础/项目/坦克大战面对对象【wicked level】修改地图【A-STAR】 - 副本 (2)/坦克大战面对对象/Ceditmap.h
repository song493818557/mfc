#pragma once
#include "map.h"
 
class Ceditmap :public Cmap, public Cmenu
{
	
public:
	Ceditmap(){
		gga.push_back("  ------------------   ");
		gga.push_back("■       2、空白     ■");//0x32 41 4  49
		gga.push_back("■       3、土墙     ■");//0x33 41 6
		gga.push_back("■       4、铁墙     ■");//0x34 41 8
		gga.push_back("■       5、河流     ■");//0x35 41 10 
		gga.push_back("■       6、障碍     ■");//0x36 41 12 		
		gga.push_back("■       7、草地     ■");//0x37 41 14 	  
		gga.push_back("■       左键画地图  ■");
		gga.push_back("■       右键清除    ■");
		gga.push_back("■       保存（S）   ■");//0X73 0X53  41 27
		gga.push_back("■       读取（L）   ■");//0X4C 0X6C  41 29
		gga.push_back("■      默认（D）    ■");//0X64 0X44  41 31
		gga.push_back("■      退出 (Q)     ■");//0X71 0X51  41 33
	
	};//导入需要用到的一些文字信息
	void Directions();//输出界面
	void outputPos(int nX, int nY);//输出测试
	void keyevent(KEY_EVENT_RECORD ker);//接收键盘的函数
	void mouseEvent(MOUSE_EVENT_RECORD mer);//接收鼠标的函数
	int get_Message();//获取事件函数
	void small_menu(int number, int map_id); //菜单的选择
	void Savemap();//保存编辑的地图
	void Readmap(int numb);//读取保存编辑的地图
	//void Printinfo(int mapid);//打印图形到界面  
private:
	int ison=0;
	int m_key_now;//接收键盘的值
	int m_key_Previous;//接收键盘的值
	int m_bool =0;//接收现在的鼠标的值
	int m_mouse_Previous;//接收上一历史鼠标的值
	int m_x;//X坐标
	int m_y;//Y坐标
	int m_mapid;//当前的选项ID
	vector<char *> gga;
};

