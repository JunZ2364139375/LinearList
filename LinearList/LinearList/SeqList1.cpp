#include<iostream>
#include<stdlib.h>
#include"LinearList1.h"
using namespace std;
const int defaultSize = 100;

template<class T>
class SeqList :public LinearList<T> {
protected:
	T * data;//�������
	int maxSize;//�������ɱ������Ŀ
	int last;//��ǰ��������λ�ã���0��ʼ
	void reSize(int newSize);

public:
	SeqList(int sz = defaultSize);
	SeqList(SeqList<T>&L);
	~SeqList();
	int Size()const { return maxSize; };
	int Length()const { return last + 1; };
	int Search(T& x)const;//�������ر�����ţ����еڼ���Ԫ�أ���
	int Locate(int i)const;//���ر��еڼ���Ԫ�أ�
	bool getData(int i, T& x)//ȡ��i��λ�õ�ֵ 
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
	bool Insert(int i, T& x);//�ڵ�i��λ��֮�����
	bool Remove(int i, T& x);//ͨ��x���ر����ֵ
	bool IsEmpty() { return last = -1 ? true : false; };
	bool IsFull() { return last = maxSize - 1 ? true : false; }
	void input();
	void output();

		SeqList<T>operator=(SeqList<T>&L);//�����帳ֵ
};


//���캯���͸��ƹ��캯��
template<class T>
SeqList<T>::SeqList(int sz) {
	if (sz > 0) {
		maxSize = sz;
		last = -1;//�Ʊ��ʵ�ʳ���Ϊ��
		data = new T[maxSize];
	}
	else if(data==NULL)
	{
		cerr << "�洢����ʧ�ܣ�" << endl;
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
		cerr << "�洢����ʧ��" << endl;
		exit(1);
	}
	for (int i = 0; i <= last + 1; i++)
	{
		L.getData(i, value);//i��λ��
		data[i - 1] = value;
	}
}

	//�Ҿ��ÿ���
	template<class T>
	void SeqList<T>::reSize(int newSize) {
		if (newSize <= 0) {
			cerr << "���ȵ������±�" << endl;
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
		return 0;//û�ҵ�fanhui0
	}

	template<class T>
	int SeqList<T>::Locate(int i) {
		if (i > 0 && i <= last + 1)
			return i;
		return 0;
	}
}

//������ɾ��
template<class T>
bool SeqList<T>::Insert(int i,T& x) {
	//���뵽��i������֮��data��i-1��֮��
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
	//�������ݣ�����˳���
	cout << "�������ݣ���ʼ����˳���,����˳�����Ԫ�ظ���" << endl;
	while (1) {
		cin >> last;
		if (last < maxSize - 1)break;
		cout << "��Ԫ�ظ������ޣ����ܳ�����Χ" << endl;
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