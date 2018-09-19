#pragma once
#include "LinearList.h"
template<class T>
struct DblNode {
	T data;
	DblNode<T>*lLink, *rLink;
	DblNode(DblNode<T>*left = nullptr, DblNode<T>*right = nullptr) :lLink(left), rLink(right) {};
	DblNode(T value, DblNode<T>*left = nullptr, DblNode<T>*right = nullptr) :data(value), lLink(left), rLink(right) {};
};

template<class T>
class DblList :public LinearList {
private:
	DblNode<T> *first;
public:
	DblList(T uniqueValue);//构造函数，建立附加头结点
	~DblList();//记得要实现
	int Length()const;
	bool isEmpty() { return first->link = first; };
	DblNode<T>* getHead()const  { return first; };//获取附加头结点的地址
	void setHead(DblNode<T>*ptr) { first = ptr; }；//取附加头结点的地址
		DblNode<T>* Search(const T&x);
	DblNode<T>* Locate(int i, int d);//在链表中定位序号为i的节点，d=0向前驱动方向，d!=0按后区方向


};

