#ifndef LINEAR_LIST
#define LINEAR_LIST

template<class T>
class LinearList {
public:
	LinearList();
	~LinearList();
	virtual int Size()const = 0;//Find the maximum volume
	virtual int Length()const = 0;//Find the maximun length of the list
	virtual int Search(T& x)const = 0;
	virtual int Locate(int i)const = 0;//在表中搜索第i个元素的位置
	virtual bool getData(int i, T& x)const = 0;
	virtual void setData(int i, T& x) = 0;
	virtual bool Insert(int i, T& x) = 0;//在表中第i个表项后插入元素
	virtual bool Remove(int i, T& x) = 0;//删除第i个表项，通过x返回
	virtual bool IsEmpty()const = 0;
	virtual bool IsFull()const = 0;
	virtual void Sort() = 0;
	virtual void input() = 0;
	virtual void output() = 0;
	virtual LinearList<T> operator=(LinearList<T>&L) = 0;//复制

};
#endif