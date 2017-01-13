#pragma once

//#define ElementType int

namespace CMyArray_T_Space {

	//定义一个枚举,表示函数运行的错误码
	enum Status
	{
		RESULT_FALSE = 0,    //失败
		RESULT_TRUE,        //成功
		RESULT_ERR_OVER,    //错误_数组越界
		RESULT_ERR_PARAMER, //错误_参数错误
		RESULT_ERR_OVERSIZE,//错误_超过最大容量
		RESULT_ERR_ONKNOW,  //错误_未知错误
	};

	template<class T>
	class CMyArray_T
	{
	public:
		CMyArray_T();
		~CMyArray_T();

		Status InitArray(    /** 构造一个线性表 */
			int size = 10      //[in] 线性表的初始大小
			);

		Status InsertArray(  /** 在线性表中第i个元素位置之前插入新的数据元素e*/
			T e,    //[in] 被插入的新值
			int i = -1        //[in] 插入的位置(在此位置之前插入)
			);

		Status DeleteArray(  /** 删除L的第i个数据元素，并用e返回其值，L的长度减1*/
			T &e,     //[out]被删除元素的值
			int i = -1          //[in] 删除元素的位置
			);
		Status ClearArray(   /** 将线性表重置为空表*/
			);
		Status ArrayEmpty(   /** 线性表是否为空*/
			bool & isEmpty     //[out]是否为空
			);
		Status ArrayLength(  /**返回L中元素个数,不存在则返回-1*/
			int & length       //[out]长度
			);
		Status GetElem(      /**用e返回L中第i个数据元素的值*/
			int i,             //[in]获取元素的位置
			T& e     //[out]被获取的元素
			);
		T operator[](int i);

		Status LocateElem(  /**返回在线性表中第1个与e相等的数据元素的位序。不存在则返回-1*/
			int startPos,      //[in]从第几个位置开始查找
			T e,     //[in]查找哪个元素
			int & pos          //[out]元素所在位置
			);
		Status SetElem(     /**用e替换L中第i个数据元素的值*/
			int i,             //[in]被设置元素的下标
			T e      //[in]设置成新值
			);

	private:
		int m_nCurrNum;	          //当前数据元素个数
		int m_nCurrSize;          //当前数据结构的容量
		T * m_pArrHead; //数据结构中的第一个数据元素的地址

		Status ExpandSpace();
	};


	//1.把cpp中的函数全部拷贝到h文件中
	//2.类和函数前面全加 template<class T1,class T2 ...>
	//3.函数的类名前加<T1,T2 ...>
	//4.把 宏 ElementType 替换成 T

	template<class T>
	CMyArray_T<T>::CMyArray_T()
	{
		m_nCurrNum = 0;	      //当前数据元素个数
		m_nCurrSize = 0;      //当前数据结构的容量
		m_pArrHead = nullptr; //数据结构中的第一个数据元素的地址
	}

	template<class T>
	CMyArray_T<T>::~CMyArray_T()
	{
		ClearArray();
	}

	/************************************
	* Access:    public
	* 函数功能:  构造一个线性表
	*
	* 参数列表:
	*   int size:  [in] 线性表的初始大小
	*
	* 返回值:    Status
	*
	*************************************/
	template<class T>
	Status CMyArray_T<T>::InitArray(int size /*= 10*/)
	{
		//1.检查是否满足初始条件
		if (m_pArrHead != nullptr)
		{
			return RESULT_FALSE;
		}

		//2.检查是否传入了正确参数				
		if (size <= 0)
		{
			return RESULT_ERR_PARAMER;
		}

		//3.实现本函数的功能
		//  构造一个空的线性表
		m_pArrHead = new T[size];
		m_nCurrNum = 0;
		m_nCurrSize = size;

		return RESULT_TRUE;
	}

	/************************************
	* Access:    public
	* 函数功能:  在线性表中第i个元素位置之前插入新的数据元素e
	*
	* 参数列表:
	*   T e:   [in] 被插入的新值
	*   int i:           [in] 插入的位置(在此位置之前插入)
	*
	* 返回值:    Status
	*
	*************************************/
	template<class T>
	Status CMyArray_T<T>::InsertArray(T e, int i)
	{
		//1.检查是否满足初始条件
		Status checkInit = InitArray();
		if (checkInit != RESULT_TRUE &&
			checkInit != RESULT_FALSE)
		{
			return checkInit; //数组没有被正常初始化
		}
		//2.检查是否传入了正确参数				
		//  2.1 处理参数的特殊值
		if (i == -1)
		{
			i = m_nCurrNum; //最后一个位置
		}
		//  2.1 检查参数是否有效
		if (i<0 || i>m_nCurrNum)
		{
			return RESULT_ERR_OVER;
		}

		//3.实现本函数的功能
		//  在线性表中第i个元素位置之前插入新的数据元素e
		//3.1   查看容量是否已满
		if (m_nCurrNum == m_nCurrSize)
		{
			//3.1.1 扩容(开辟新的空间)
			Status checkExpand = ExpandSpace();
			//3.1.2 扩容的结果检查,是否成功
			if (checkExpand != RESULT_TRUE)
			{
				return checkExpand;
			}
		}

		//3.2   插入元素
		//3.2.1 把i位置以及其后面的元素都往后面移动一下
		for (int j = m_nCurrNum - 1; j >= i; j--)
		{
			m_pArrHead[j + 1] = m_pArrHead[j];
		}
		//3.2.2 把新元素插在i位置上
		m_pArrHead[i] = e;

		m_nCurrNum++;
		return RESULT_TRUE;
	}

	/************************************
	* Access:    public
	* 函数功能:  删除L的第i个数据元素，并用e返回其值，L的长度减1
	*
	* 参数列表:
	*   int i:            [in] 删除元素的位置
	*   T & e:  [out]被删除元素的值
	*
	* 返回值:    Status
	*
	*************************************/
	template<class T>
	Status CMyArray_T<T>::DeleteArray(T &e, int i)
	{
		//1.检查是否满足初始条件
		if (m_pArrHead == nullptr)
		{
			return RESULT_FALSE;
		}
		//2.检查是否传入了正确参数	
		//  2.1 处理参数的特殊值
		if (i == -1)
		{
			i = m_nCurrNum - 1;
		}
		//  2.1 检查参数是否有效
		if (i < 0 || i >= m_nCurrNum)
		{
			return RESULT_ERR_OVER;
		}
		//3.实现本函数的功能
		//删除L的第i个数据元素，并用e返回其值，L的长度减1
		//3.1 获取返回值
		e = m_pArrHead[i];
		//3.2 把第i个元素后面的所有元素都往前面移动一下
		for (int j = i; j < m_nCurrNum - 1; j++)
		{
			m_pArrHead[j] = m_pArrHead[j + 1];
		}
		//3.3 更新数据成员
		m_nCurrNum--;

		return RESULT_TRUE;
	}

	/************************************
	* Access:    public
	* 函数功能:  将线性表重置为空表
	*
	* 参数列表:
	*
	* 返回值:    Status
	*
	*************************************/
	template<class T>
	Status CMyArray_T<T>::ClearArray()
	{
		if (!m_pArrHead)
		{
			delete[]m_pArrHead;
		}
		m_nCurrNum = 0;
		m_nCurrSize = 0;
		m_pArrHead = nullptr;

		return RESULT_TRUE;
	}

	/************************************
	* Access:    public
	* 函数功能:  线性表是否为空
	*
	* 参数列表:
	*   bool & isEmpty:  [out]是否为空
	*
	* 返回值:    Status
	*
	*************************************/
	template<class T>
	Status CMyArray_T<T>::ArrayEmpty(bool & isEmpty)
	{
		if (m_nCurrNum == 0)
		{
			isEmpty = true;
		}
		else
		{
			isEmpty = false;
		}
		return RESULT_TRUE;
	}

	/************************************
	* Access:    public
	* 函数功能:  返回L中元素个数
	*
	* 参数列表:
	*   int & length:   [out]长度
	*
	* 返回值:    Status
	*
	*************************************/
	template<class T>
	Status CMyArray_T<T>::ArrayLength(int & length)
	{
		//1.检查是否满足初始条件
		if (m_pArrHead == nullptr)
		{
			length = -1;
			return RESULT_FALSE;
		}

		//2.检查是否传入了正确参数				
		//  2.1 处理参数的特殊值
		//  2.1 检查参数是否有效

		//3.实现本函数的功能
		//  返回L中元素个数
		length = m_nCurrNum;
		return RESULT_TRUE;
	}

	/************************************
	* Access:    public
	* 函数功能:  用e返回L中第i个数据元素的值
	*
	* 参数列表:
	*   int i:           [in]获取元素的位置
	*   T e:   [out]被获取的元素
	*
	* 返回值:    Status
	*
	*************************************/
	template<class T>
	Status CMyArray_T<T>::GetElem(int i, T& e)
	{
		//1.检查是否满足初始条件
		if (m_pArrHead == nullptr)
		{
			return RESULT_FALSE;
		}

		//2.检查是否传入了正确参数	
		//  2.1 处理参数的特殊值
		//  2.2 检查参数是否有效
		if (i < 0 || i >= m_nCurrNum)
		{
			return RESULT_ERR_OVER;
		}
		//3.实现本函数的功能
		//  用e返回L中第i个数据元素的值
		e = m_pArrHead[i];

		return RESULT_TRUE;
	}

	template<class T>
	T CMyArray_T<T>::operator[](int i)
	{
		T e;
		GetElem(i, e);
		return e;
	}

	/************************************
	* Access:    public
	* 函数功能:  返回在线性表中第1个与e相等的数据元素的位序。不存在则返回-1
	*
	* 参数列表:
	*   int startPos:  [in]从第几个位置开始查找
	*   T:   [in]查找哪个元素
	*   int & pos:     [out]元素所在位置
	*
	* 返回值:    Status
	*
	*************************************/
	template<class T>
	Status CMyArray_T<T>::LocateElem(int startPos, T e, int & pos)
	{
		//1.检查是否满足初始条件
		if (m_pArrHead == nullptr)
		{
			pos = -1;
			return RESULT_FALSE;
		}

		//2.检查是否传入了正确参数				
		//  2.1 处理参数的特殊值
		//  2.2 检查参数是否有效
		if (startPos < 0 || startPos >= m_nCurrNum)
		{
			return RESULT_ERR_PARAMER;
		}

		//3.实现本函数的功能
		//  返回在线性表中第1个与e相等的数据元素的位序。不存在则返回-1
		//3.1 通过for循环寻找指定元素
		pos = -1;
		for (size_t i = startPos; i < m_nCurrNum; i++)
		{
			if (m_pArrHead[i] == e)
			{
				pos = i;
				break;
			}
		}
		return RESULT_TRUE;
	}

	/************************************
	* Access:    public
	* 函数功能:  用e替换L中第i个数据元素的值
	*
	* 参数列表:
	*   int i:          [in]被设置元素的下标
	*   T e:  [in]设置成新值
	*
	* 返回值:    Status
	*
	*************************************/
	template<class T>
	Status CMyArray_T<T>::SetElem(int i, T e)
	{
		//1.检查是否满足初始条件
		if (m_pArrHead == nullptr)
		{
			return RESULT_FALSE;
		}

		//2.检查是否传入了正确参数				
		//  2.1 处理参数的特殊值
		//  2.2 检查参数是否有效
		if (i < 0 || i >= m_nCurrNum)
		{
			return RESULT_ERR_OVER;
		}

		//3.实现本函数的功能
		//  用e替换L中第i个数据元素的值
		m_pArrHead[i] = e;

		return RESULT_TRUE;
	}

	//扩大数组的容量
	template<class T>
	Status CMyArray_T<T>::ExpandSpace()
	{
		//扩大容量的规则(每次扩大到原来的2倍)
		//1. 开辟新空间
		T * temp = nullptr;
		try
		{
			temp = new T[2 * m_nCurrSize];
		}
		catch (...)
		{
			return RESULT_FALSE;
		}
		//2. 原来的赋值到新空间
		memcpy_s(temp, m_nCurrSize*sizeof(T),
			m_pArrHead, m_nCurrSize*sizeof(T));
		//3. 释放原来的控件
		delete[]m_pArrHead;
		//4. 更新数据成员
		m_pArrHead = temp;
		m_nCurrSize = 2 * m_nCurrSize;

		return RESULT_TRUE;
	}


	/*
	ADT 线性表(List)
	Data
	数据对象：线性表的数据对象集合为{𝑎_1, 𝑎_2, ...𝑎_𝑛}，每个元素类型均为DataType。
	数据关系：除第一个元素𝑎_1外，每一个元素有且只有一个直接前驱元素，
	除了最后一个元素𝑎_𝑛外，每个元素有且只有一个直接后继元素，数据元素之间的关系是一对一的关系。
	Operation
	InitList(&L):
	操作结果：构造一个空的线性表L
	InsertList(&L,i,e):
	初始条件：线性表L已存在，0<=i<=ListLength(L)
	操作结果：在L中第i个元素位置之前插入新的数据元素e，L的长度加1
	DeleteList(&L,i,&e):
	初始条件：线性表L已存在且非空，0<=i<ListLength(L)
	操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
	ClearList(&L):
	初始条件：线性表L已存在         操作结果：将L重置为空表
	ListEmpty(L):
	初始条件：线性表L已存在
	操作结果：若L为空表，则返回true，否则返回false
	ListLength(L):
	初始条件：线性表L已存在         操作结果：返回L中元素个数
	GetElem(L,i,&e):
	初始条件：线性表L已存在，0<= i <ListLength(L)
	操作结果：用e返回L中第i个数据元素的值
	LocateElem(L,e):
	初始条件：线性表L已存在。
	操作结果：返回在线性表中第1个与e相等的数据元素的位序。不存在则返回-1
	SetElem(L,i,e):
	初始条件：线性表L已存在，0<= i <ListLength(L)
	操作结果：用e替换L中第i个数据元素的值
	……
	endADT
	*/


}