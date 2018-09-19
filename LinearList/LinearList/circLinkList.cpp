#include"LinearList1.h"
//��δ��ȫʵ��
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
	CircList(const T&x);//���캯��
	CircList(CircList<T>&L);//���ƹ��캯��
	~CircList();//��������
	int Length()const;//����ѭ������ĳ���
	bool IsEmpty() { return first->link = first ? true : false; }
	CircList<T>* getHead()const;//���ظ���ͷ���ĵ�ַ
	void setHead(CircLinkNode<T>*p);//���ø���ͷ���ĵ�ַ��
	CircLinkNode<T>*Search(T& x);//������������x�Ľڵ㣬�������ַ
	CircLinkNode<T>*Locate(int i);//������i��Ԫ�صĵ�ַ��
	T* getData(int i);//���ص�i��Ԫ�ص�ֵ
	void setData(int i,T& x);
	bool Insert(int i, T& x);//�ڵ�i��Ԫ�غ����ڵ�
	bool Remove(int i, T&x);//ɾ����i����㣬x��������ֵ

	CircLinkNode<T>*getHead() { return first; };
	CircLinkNode<T>*getRear() { return last; };

};


template<class T>
CircList<T>::CircList(const T&x) {
	first = last = new CircLinkNode<T>(x);
	first->link = first;
}


//���ƹ��캯��
template<class T>
CircList<T>::CircList(CircList<T>& L) {
#if 0
	T value;
	LinkNode<T>*srcptr = L.getHead();//�����Ʊ�ĸ���ͷ����ַ
	LinkNode<T>*destptr = first = new LinkNode<T>;//���ƹ��캯�����տ�ʼĿ�굥����Ϊ��
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