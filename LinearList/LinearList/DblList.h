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
	DblList(T uniqueValue);//���캯������������ͷ���
	~DblList();//�ǵ�Ҫʵ��
	int Length()const;
	bool isEmpty() { return first->link = first; };
	DblNode<T>* getHead()const  { return first; };//��ȡ����ͷ���ĵ�ַ
	void setHead(DblNode<T>*ptr) { first = ptr; }��//ȡ����ͷ���ĵ�ַ
		DblNode<T>* Search(const T&x);
	DblNode<T>* Locate(int i, int d);//�������ж�λ���Ϊi�Ľڵ㣬d=0��ǰ��������d!=0����������


};

