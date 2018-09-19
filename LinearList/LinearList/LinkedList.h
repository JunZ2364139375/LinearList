#pragma once
#include"LinearList1.h"
//��������ඨ��
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
	void makeEmpty();//������ֵΪ�գ�
	int Length()const;
	LinkNode<T>* getHead()const { return first; }//���ظ���ͷ���ĵ�ַ
	LinkNode<T>*Search(T&x);
	LinkNode<T>*Loncate(int i);//������i��Ԫ�صĵ�ַ
	bool getData(int i, T&x)const;//ȡ����i��Ԫ�ص�ֵ
	void setData(int i, T&x);//��x�޸ĵ�i��Ԫ�ص�ֵ
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
	bool IsEmpty()const { return first->link == nullptr ? true : false; };
	bool IsFull()const { return false; }//?????????????????
	void Sort();
	void inputFront(T endTag);
	void inputRear(T endTag);
	void output();
	List<T>&operator=(List<T>&L);//���ظ�ֵ����

};

