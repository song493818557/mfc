//const �޶���(C):"һ�����ܸı�ֵ�ı���"
//const �޶���(C++):"һ�������������ĳ���"
//#define NNUNB 100


//const+��ͨ����
void testConst1()
{
	int nNunA;            //��ͨ����

	//const int nNunB;    //const���͵ĳ���,��Ҫ����ֵ
	const int nNunB = 100;
	nNunA = 999;
	nNunB = 777;          //const���͵ĳ������ܹ����ı�

	int arr[nNunB];       //��������Ϊ���鳤��

}

//const+ָ������
//����ָ�� ָ�볣��
void testConst2()
{
	//��ͨconst����
	const int nNumA = 10;   

	int nData1 = 15;
	int nData2 = 15;

	//����ָ��: ָ������ָ��
	const int * ptrDataA;
	//int const * ptrDataC;//��һ��д��,���Ƽ�����д
	ptrDataA = &nData2; 

	ptrDataA = &nNumA;    //1.�����ܹ����ı�
	ptrDataA = &nData1;

	*ptrDataA = 200;      //2.ָ����ǳ���,���ܱ��ı�

	//ָ�볣��
	//int * const ptrDataB;
	int * const ptrDataB = &nData1; //1.�����ǳ���,��Ҫ����ֵ
	
	ptrDataB = &pDataB;             //2.�����ܱ��ı�

	*ptrDataB = 100;                //3.ָ����Ǳ���,�ܹ����ı�


	
}

void main()
{
	
}