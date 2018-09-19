#ifndef LINEAR_LIST
#define LINEAR_LIST

template<class T>
class LinearList{
public:
LinearList();
~LinearList();
virtal int Size()const=0;//Find the maximum volume
virtal int Length()const=0;//Find the maximun length of the list
virtal int Search(T& x)const=0;
virtal int Locate(int i)const=0;//在表中搜索第i个元素的位置
virtal bool getData(int i,T& x)const=0;
virtal void setData(int i,T& x)=0;
virtal bool Insert(int i,T& x)=0;//在表中第i个表项后插入元素
virtal bool Remove(int i,T& x)=0;//删除第i个表项，通过x返回
virtal bool IsEmpty()const=0;
virtal bool IsFull()const=0;
virtal void Sort()=0;
virtal void input()=0;
virtal void output()=0;
virtal LinearList<T> operator=(LinearList<T>&L)=0;//复制

}


#endif