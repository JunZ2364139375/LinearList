#pragma once
#include "LinearList.h"
//链表节点类定义
template<class T>
struct DblNode{
	private:
	T data;
	DblNode<T>*lLink, *rLink;
	DblNode(DblNode<T>*left = nullptr, DblNode<T>*right = nullptr) :lLink(left), rLink(right) {};
	DblNode(T value, DblNode<T>*left = nullptr, DblNode<T>*right = nullptr) :data(value), lLink(left), rLink(right) {};
};

//链表类定义
template<class T>
class DblList :public LinearList {
private:
	DblNode<T> *first;
public:
	DblList(T uniqueValue);//构造函数，建立附加头结点
	~DblList();//析构函数，记得要实现
	int Length()const;
	bool isEmpty() { return first->link = first; };
	DblNode<T>* getHead()const  { return first; };//取附加头结点地址
	void setHead(DblNode<T>*ptr) { first = ptr; };//设置附加头结点地址
	DblNode<T>* Search(const T&x);//在链表中沿后方向寻找等于给定值结点
	DblNode<T>* Locate(int i, int d);//在链表中定位序号为（i>=0）的节点，d=0按前驱方向，d!=0按猴急方向
	bool Insert(int i,T &x,int d);//在链表i个结点后插入一个x结点，d=0按前驱方向，d！=0按猴急方向
	bool Remove(int i,T &x,int d);//删除第i个结点，x返回其值，d=0按前驱方向，d！=按猴急方向

};

template<class T>
DblList<T>::DblList(T uniqueValue){
	//构造函数；建立双向循环链表的附加头结点，他包含了一个用于某些特定情况的值
	first=new DblNode<T>(uniqueValue);
	if(first=NULL){cerr<<"存储分配出错"<<endl;
	exit(1);}
	first->rLink=first->lLink=first;
};


template<class T>
int DblList<T>::Length()const{
	DblNode<T>* current=first->rLink;
	int count=0;
	while(current!=first){
		count++;
		current=current->rLink;
	}
	count++;
};

template<class T>
DblNode<T>* DblList<T>::Search(const T&x){
	#if 0
	DblNode<T>* current=first->rLink;
	while(current->data!=x&&current!=first){
		current=current->rLink;
	}
if(current!=first){
	return current;
}
return nullptr;
#endif

DblNode<T>* current=first->rLink;
while(current!=first&&current->data!=x){
	current=current->rlink;
}
if(current!=first) return current;
else {return nullptr};

};


template<class T>
DblNode<T>* DblList<T>::Locate(int i,int d){

#if 0
	//在带附加头结点的双向链表中按d所指的方向寻找第i个结点地址，d=0按前驱方向，d！=0按后机方向
	if(i=0)return first;
	if(i>this.Length()) return nullptr;
	if(i<0)return nullptr;
	if(d=0){
	DblNode<T>* current=first->lLink;
	for(int j=0;j<i;j++){
		current=current->lLink;
	}
	return current;

	}
	if(d!=0){
		DblNode<T>* current=first->rLink;
	for(int j=0;j<i;j++){
		current=current->rLink;
	}
	return current;

	}
#endif

if(first->rlink==first||i==0){
		return first;
	}
	DblNode<T>* current;
	if (d == 0)current = first->lLink;//搜索方向
	else current == first->rLink;
	for (int j = 0; j < i; j++) {
		if (current == first)break;
		else if (d == 0)current = current->lLink;
		else current = current->rLink;
	}
	if (current != first)return current;
	else return nullptr;

}

template<class T>
bool DblList<T>::Insert(int i, const T& x, int d) {
	//建立一个包含值x的新节点，并将其按d指定的方向插入到i个结点之后；
#if 0
	DblNode<T>*current=first->rlink;
	current->data = x;
	if (current == first) {
		current->lLink = first;
		first->lLink = current;
		current->rLink = first;
	}

		if (d == 0) {
			DblNode<T>* ins = new DblNode<T>*();
			DblNode<T>*	fcurrent = Locate(i - 1, d);
			ins->lLink = fcurrent->lLink;
			fcurrent->lLink->rLink = ins;
			fcurrent->lLink = ins;
			ins->rLink = fcurrent;
			

	}
	if (d != 1) {
		DblNode<T>* ins = new DblNode<T>();
		DblNode<T>*	fcurrent = Locate(i - 1, d);
		ins->rLink = fcurrent->rLink;
		fcurrent->rLink->lLink = ins;
		fcurrent->rLink = ins;
		ins->lLink = fcurrent;

	}
#endif

	DblNode<T>*current = Locate(i, d);//查找第i个结点
	if (current == nullptr)return false;//i不合理，插入失败
	DblNode<T>* newNode = new DblNode<T>();//这个的逻辑结构是怎么样的
	if (newNode == nullptr) { cerr << "存储分配失败" << endl; }
	if (d == 0) {
		//有四步造作就够了。
		newNode->lLink = current->lLink;
		current->lLink = newNode;
		newNode->lLink->rLink = newNode;
		newNode->rLink = current;
	}
	else {
		newNode->rLink = current->rLink;
		current->rLink = newNode;
		newNode->rLink->lLink = newNode;
		newNode->lLink = current;
	}
	return true;
}

template<class T>
bool DblList<T>::Remove(int i, T &x, int d) {
	//在带附加头结点的双向循环链表中按照d所指的方向删除第i个结点；
#if 0
	DblNode<T>* delNode = Locate(i, d);
	if (d == 0) {
		delNode->rLink->lLink = delNode->lLink;
		delNode->lLink->rLink = delNode->rLink;
	}
	else
	{
		delNode->rLink->lLink = delNode->lLink;
		delNode->lLink->rLink = delNode->rLink;
	}
	delete delNode;
#endif

	DblNode<T>*current = Locate(i, d);
	if (currnet = nullptr) {
		return false;
		current->rLink->lLink = current->lLink;
		current->lLink->rLink = current->rLink;
		x = current->data;
		delete current;
		return true;
	}
}




