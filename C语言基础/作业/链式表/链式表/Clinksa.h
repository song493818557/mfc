#pragma once
class Clinks{
public:

	struct Nothing
	{
		int Ndata;
		Nothing * Pnext;
	};
	Clinks();
	bool Finsert(int nLoc, int ndata);
	int Fdelete(int nloc, int &ndata);
	//查找等于E的元素的值 返回给Ndata
	int Fselect(int e, int &ndata);
	void Fdeleteall();
	
	void Fprint(){
		if (m_head == NULL)
		{
			return;
		}
		Nothing * temp = m_head;
		for (int i = 0; i < m_lenth;i++)
		{
			printf("%d\n", temp->Ndata);
			temp = temp->Pnext;
		}

	}
private:
	int m_lenth;
	Nothing * m_head;
};
