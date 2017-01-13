
//const 限定符:"一个不能改变值的变量"
void main()
{
	int nNunA;            //普通变量
	//const int nNunB;      //const类型的变量
	const int nNunB = 100;//定义的时候赋值才有意义
	nNunA = 999;         
	nNunB = 777;          //const类型的变量不能够被改变

	int arr[nNunB];       //变量不能作为数组长度
}