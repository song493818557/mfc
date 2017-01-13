//const 限定符(C):"一个不能改变值的变量"
//const 限定符(C++):"一个有类型描述的常量"
//#define NNUNB 100


//const+普通类型
void testConst1()
{
	int nNunA;            //普通变量

	//const int nNunB;    //const类型的常量,需要赋初值
	const int nNunB = 100;
	nNunA = 999;
	nNunB = 777;          //const类型的常量不能够被改变

	int arr[nNunB];       //常量能作为数组长度

}

//const+指针类型
//常量指针 指针常量
void testConst2()
{
	//普通const常量
	const int nNumA = 10;   

	int nData1 = 15;
	int nData2 = 15;

	//常量指针: 指向常量的指针
	const int * ptrDataA;
	//int const * ptrDataC;//另一种写法,不推荐这样写
	ptrDataA = &nData2; 

	ptrDataA = &nNumA;    //1.自身能够被改变
	ptrDataA = &nData1;

	*ptrDataA = 200;      //2.指向的是常量,不能被改变

	//指针常量
	//int * const ptrDataB;
	int * const ptrDataB = &nData1; //1.自身是常量,需要赋初值
	
	ptrDataB = &pDataB;             //2.自身不能被改变

	*ptrDataB = 100;                //3.指向的是变量,能够被改变


	
}

void main()
{
	
}