#pragma once
#include"LinearList1.h"
//单链表的类定义
template<class T>
struct LinkNode
{
	T data;
	LinkNode<T>*link;
	LinkNode(LinkNode<T>*ptr = nullptr) { link = ptr; }
	LinkNode(const T&item,LinkNode<T>*ptr = nullptr) {
		data = item;
		link = ptr;
	}
};

template<class T>
class List :public LinearList<T>
{
protected:
	LinkNode<T>*first;
public:
	List() { first = new LinkNode<T>; }
	List(const T& x) { first = LinkNode<T>(x); }
	List(List<T>&L);
	~List() { makeEmpty(); }
	void makeEmpty();//将链表值为空；
	int Length()const;
	LinkNode<T>* getHead()const { return first; }//返回附加头结点的地址
	LinkNode<T>*Search(T&x);
	LinkNode<T>*Loncate(int i);//搜索第i个元素的地址
	bool getData(int i, T&x)const;//取出第i个元素的值
	void setData(int i, T&x);//用x修改第i个元素的值
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
	bool IsEmpty()const { return first->link == nullptr ? true : false; };
	bool IsFull()const { return false; }//?????????????????
	void Sort();
	void inputFront(T endTag);
	void inputRear(T endTag);
	void output();
	List<T>&operator=(List<T>&L);//重载赋值函数

};

