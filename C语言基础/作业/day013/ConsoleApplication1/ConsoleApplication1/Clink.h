#pragma once
#define TEAMINT int
class Clink
{
public: 
	typedef struct _NODE{
		TEAMINT nData;
		_NODE * nNext;
		_NODE * nPrev; 
	}NODE;
	Clink():m_length(1){ }; 
	void Insertlink(TEAMINT data,int loca = -1);//��������
	void Deletelink(TEAMINT &data, int loca = -1);//ɾ������ Ĭ��ɾ������
	void Clearlink();
	~Clink(){
		//Clearlink();
	};
private:
	int m_length;
	NODE * m_phead;
};

