#include"LinearList1.h"
//还未完全实现
template<class T>
struct CircLinkNode
{
	T data;
	CircLinkNode<T>*link;
	CircLinkNode(CircLinkNode<T>*next = nullptr) :link(next) {};
	CircLinkNode(T d, CircLinkNode<T>*next = nullptr) :data(d), link(next) {};
};

template<class T>
class CircList :public LinearList<T> {
protected:
	CircLinkNode<T>*first, *last;
public:
	CircList(const T&x);//构造函数
	CircList(CircList<T>&L);//复制构造函数
	~CircList();//析构函数
	int Length()const;//计算循环链表的长度
	bool IsEmpty() { return first->link = first ? true : false; }
	CircList<T>* getHead()const;//返回附加头结点的地址
	void setHead(CircLinkNode<T>*p);//设置附加头结点的地址；
	CircLinkNode<T>*Search(T& x);//搜索含有数据x的节点，返回其地址
	CircLinkNode<T>*Locate(int i);//搜索第i个元素的地址；
	T* getData(int i);//返回第i个元素的值
	void setData(int i,T& x);
	bool Insert(int i, T& x);//在第i个元素后插入节点
	bool Remove(int i, T&x);//删除第i个结点，x返回他的值

	CircLinkNode<T>*getHead() { return first; };
	CircLinkNode<T>*getRear() { return last; };

};


template<class T>
CircList<T>::CircList(const T&x) {
	first = last = new CircLinkNode<T>(x);
	first->link = first;
}


//复制构造函数
template<class T>
CircList<T>::CircList(CircList<T>& L) {
#if 0
	T value;
	LinkNode<T>*srcptr = L.getHead();//被复制表的附加头结点地址
	LinkNode<T>*destptr = first = new LinkNode<T>;//复制构造函数，刚开始目标单链表为空
	while (srcptr->link != NULL) {
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = nullptr;
#endif
	
	T val;
	CircLinkNode<T>*srcptr = L.getHead();
	CircLinkNode<T>*destptr = new CircLinkNode<T>;
	first = destptr;

	while (srcptr->link!=first)
	{
		val = srcptr->link->data;
		destptr->link = new CircLinkNode<T>(val);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	last = destptr;
	last->link = first;
}