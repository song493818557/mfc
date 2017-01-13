#include "stdafx.h"
#include "Cstring.h" 

#include <sstream>
namespace mystring{

	void Cstring::input(){
		fstream mout,min;
		try
		{
		mout.open("bb.txt", ios::out | ios::app );
		if (!mout.eof()) throw 1; //文件打开成功 
		}
		catch (int e)
		{ 
			 cout << "打开成功" << endl; 
		}
		char a[100]; 
		while (a[0] != '!'&&a[1]!='\0')
		{
			try
			{
			 cin >> a;
			if (cin.fail())  
			{
				cin.clear();
				char c;
				cin >> c;
				throw 3;//键盘输入失败
			}
			}
			catch (int e)
			{ 
				cout << "键盘输入失败" << endl;
			}
			int temp = strlen(a);
			for (int i = 0; i < temp; i++)
			{
				if (islower(a[i]))
				{
					a[i] = toupper(a[i]);
				}				
			}
			//mout.put(a);
			try
			{
				mout << a << endl;
				throw 4; //写入成功
			}
			catch (int e)
			{
				cout << "文件写入成功" << endl;
			}
		}
		 mout.close();
		 
		}
	 //编写一个文件的内容附着另外一个文件中
	void Cstring::copy(char *address, char *address1){

		fstream out(address, ios::out | ios::app);
		ifstream in(address1);
		  
		for (string oneline; getline(in, oneline);)
		{
			out << oneline << endl;
		}
		in.close();
		out.close();
		
	}
	Cstring::Cstring()
	{
	}
	Cstring::~Cstring()
	{
	}

 
	void Castring::insert(int data){
		if (m_length==m_maxlength)
		{
			m_maxlength *= 2;
			int * temp = new int[m_maxlength];
			memset(temp, 0, m_maxlength);
			memcpy(temp, m_data, m_maxlength*sizeof(int));
			delete[]m_data;
			m_data = new int[m_maxlength];
			memcpy(m_data, temp, m_maxlength*sizeof(int));
			delete[]temp;
		}
			m_data[m_length] = data;
			m_length++;
		}
	void  Castring::adelete(int data){
			int i = 0;
			for (; i < m_length; i++)
			{
				if (m_data[i]==data)
				{
				
					m_data[i] = m_data[m_length - 1];
					m_data[m_length - 1] = 0;
					break;
				}
			}
			//因为有个占位的问题 等下处理排序的时候删除后进行自动处理一次
		}
	void  Castring::asearch(int data){
			
		for (int i = 0; i < m_length; i++)
			{
				if (m_data[i] == data)
				{
					cout << "已经找到" << data << ",下标为:" <<i<< endl;
					break;
				}
			}
		}
		//最大值排序为1  最小值排序为2
	void  Castring::ashort(int data){
			for (int i = 0; i < m_length; i++)
			{
				for (int j = 0; j < m_length-i-1; j++)
				{
					int temp;
					if (m_data[j]<m_data[j+1] && data == 1)
					{
						 temp = m_data[j];
						 m_data[j] = m_data[j+1];
						 m_data[j+1] = temp;
						
					}
					else if (m_data[j]>m_data[j + 1] && data == 2)
					{
						temp = m_data[j];
						m_data[j] = m_data[j + 1];
						m_data[j + 1] = temp;
					}
					
				}
			}
			
		} 
}