#include<iostream>
#include<stdlib.h>
#include"LinearList1.h"
using namespace std;
const int defaultSize = 100;

template<class T>
class SeqList :public LinearList<T> {
protected:
	T * data;//存放数组
	int maxSize;//最大可容纳表项的数目
	int last;//当前表项的最后位置，从0开始
	void reSize(int newSize);

public:
	SeqList(int sz = defaultSize);
	SeqList(SeqList<T>&L);
	~SeqList();
	int Size()const { return maxSize; };
	int Length()const { return last + 1; };
	int Search(T& x)const;//搜索返回表项序号（表中第几个元素）；
	int Locate(int i)const;//返回表中第几个元素；
	bool getData(int i, T& x)//取第i个位置的值 
	{
		if (i > 0 && i <= last+1)
		{
			x = data[i - 1];
			return true;
		}
		else return false;
		}
	void setData(int i,T& x){
		if (i > 0 && i <= last + 1)
			data[i - 1] = x;
	}
	bool Insert(int i, T& x);//在第i个位置之后插入
	bool Remove(int i, T& x);//通过x返回表项的值
	bool IsEmpty() { return last = -1 ? true : false; };
	bool IsFull() { return last = maxSize - 1 ? true : false; }
	void input();
	void output();

		SeqList<T>operator=(SeqList<T>&L);//表整体赋值
};


//构造函数和复制构造函数
template<class T>
SeqList<T>::SeqList(int sz) {
	if (sz > 0) {
		maxSize = sz;
		last = -1;//制表的实际长度为空
		data = new T[maxSize];
	}
	else if(data==NULL)
	{
		cerr << "存储分配失败！" << endl;
		exit(1);
	}
}

template<class T>
SeqList<T>::~SeqList() {
	delete data;
}
template<class T>
SeqList<T>::SeqList(SeqList<T>&L) {
	maxSize = L.Size();
	last = L.Length() - 1;
	T value;
	data = new T[maxSize];
	if (data == NULL)
	{
		cerr << "存储分配失败" << endl;
		exit(1);
	}
	for (int i = 0; i <= last + 1; i++)
	{
		L.getData(i, value);//i是位置
		data[i - 1] = value;
	}
}

	//我觉得可以
	template<class T>
	void SeqList<T>::reSize(int newSize) {
		if (newSize <= 0) {
			cerr << "无先的数组下标" << endl;
			exit(1);
		}
		if (newSize != maxSize) {
			T* haha = new T[newSize];
			if (haha == NULL) {
				cerr << "!!!" << endl;
				exit(1);
			}
			int n = last + 1;
			for (int i = 0; i < n; i++)
			{
				haha[i] = data[i];
			}
			delete data;
			data = haha;
			maxSize = newSize;
		}
	
}

template<class T>
int SeqList<T>::Search(T& x)const {
	for (int i = 0; i < last + 1; i++) {
		if (x == data[i])
			return i + 1;
		return 0;//没找到fanhui0
	}

	template<class T>
	int SeqList<T>::Locate(int i) {
		if (i > 0 && i <= last + 1)
			return i;
		return 0;
	}
}

//插入与删除
template<class T>
bool SeqList<T>::Insert(int i,T& x) {
	//插入到第i个表项之后，data【i-1】之后；
	if (i < 0 || i >last + 1)
		return false;
	for(j=last;j>i;j--)
		data[j + 1] = data[j];
	data[i] = x;
	last++;
	return true;

}


template<class T>
bool SeqList<T>::Remove(int i,T& x)
{
	if (i<0 || i>last + 1)
		return false;
	for (j = i - 1; j <= last; j++)
		data[j] = data[j + 1];
	last--;
	return true;
}


template<class T>
void SeqList<T>::input() {
	//输入数据，建立顺序表；
	cout << "输入数据，开始建立顺序表,输入顺序表中元素个数" << endl;
	while (1) {
		cin >> last;
		if (last < maxSize - 1)break;
		cout << "表元素个数有无，不能超过范围" << endl;
	}

	for (int i = 0; i <= last; i++)
	{
		cin >> data[i];
		cout << i + 1 << ":" << endl;
	}
}

	template<class T>
	void SeqList<T>::output()
	{
		for(auto i:data){
			cout <<i<< endl;
	}
}