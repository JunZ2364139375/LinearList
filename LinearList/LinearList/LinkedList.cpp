#include"LinkedList.h"

template<class T>
List<T>::List(List<T>&L) {
	//List is a single Link;
	//�ҵİ汾��ֻ����ֵ�ĸ���
#if 0
	int a=L.Length();
	LinkNode<T>*mubiao=first;
	LinkNode<T>*shucu=L.first;
	for (int i = 0; i < a; i++)
	{
		mubiao->data = shucu->data;
		mubiao = mubiao->link;
		shucu = shucu->link;
	}
	#endif

	//�̲İ汾
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
}

template<class T>
 void List<T>::makeEmpty() {
#if 0
	 //�Լ��İ汾
#endif

	 LinkNode<T>*q;
	 while (first->link != nullptr) {
		 q = first->link;
		 first->link = q->link;//firstָ��ڶ�����㣻
		 delete q;
	 }
}

 template<class T>
 int  List<T>::Length()const {

#if 0
	 int count = 0;
	 LinkNode<T>*p;
	 p = first->link;
	 while (p->link != nullptr) {
		 length++;
		 p = p->link;
	 }
	 count++;
	 return count;
#endif

#if 0
	 //�α��汾
	 LinkNode<T>*p = first->link;
	 int count = 0;
	 while (p != nullptr) {
		 p = p->link;
		 count++;
	 }
	 return count;
#endif

 }

 template<class T>
 LinkNode<T>* List<T>::Search(T& x) {
	 //������ͷ����Search()
#if 0
	 //�Լ��汾
	 LinkNode<T>* p;
	 p = first->link;
	 while (p != nullptr) {
		 if (p->data == x)
			 return p;
	 }
		 else {
			 p = p->link;
		 }
 }
 return p;
#endif


#if 0
 LinkNode<T>*current = first->link;
 while (current != nullptr) {
	 if (current->data == x)break;
	 else current = current->link;
 }
	 return current;
 
#endif
 }


 template<class T>
 LinkNode<T>* List<T>::Loncate(int i) {
	 //��λ����,���ر��е�i��Ԫ�صĵ�ַ
	 if (i < 0)return nullptr;
	 LinkNode<T>*current = first;
	 int k = 0;
	 while (current != nullptr&&k < i) {
		 current = current->link;
		 k++;
	 }
	 return current;//���ص�i�����ĵ�ַ��������null����ʾiֵ̫��
 }

 
 
 template<class T>
 bool List<T>::getData(int i, T& x)const {
#if 0
	 if (i < 0)return nullptr;
	 LinkNode<T>*current = first;
	 int k = 0;
	 while (current != nullptr&&k < i) {
		 current = current->link;
		 k++;
	 }
	 x=current->data;
	 return true;
#endif

	 //�α�
 if (i <= 0)return nullptr;
	 LinkNode<T>*current = Loncate(i);
	 if (current = nullptr)return false;//iֵtaida
	 else { x = current->data; return true; }

 };


template<class T>
void List<T>::setData(int i, T& x) {
	//�������i��ֵ��ֵx
	if (i <= 0)return;
	LinkNode<T>*current = Loncate(i);
	if (current == nullptr)return;
	current->data = x;
	
}

template<class T>
bool List<T>::Insert(int i, T&x) {
	//����Ԫ��x���ڵ�i�����֮��
#if 0
	if (i <= 0)return false;
	LinkNode<T>*current = Loncate(i);
	if (current == nullptr)return false;
	LinkNode<T>*NewNode = new LinkNode<T>(x);
	p->link = current->link;
	current->link = p;
	return true;
#endif
	//�α�
	LinkNode<T>*current = Loncate(i);
	if (current == false)return false;
	LinkNode<T>*newNode = new LinkNode<t>(x);
	if (newNode == nullptr)cerr << "�洢�������" << endl;
	newNode->link = current->link;
	current->link = newNode;
	return true;
}

template<class T>
bool List<T>::Remove(int i, T& x) {
	//ɾ������i��Ԫ��
#if 0
	if (i < 0)return false;
	LinkNode<T>*current = Loncate(i-1);
	LinkNode<T>*de = Loncate(i);
	current->link = de->link;
	x = de->data;
	delete de;
	return true;
#endif
	//�̲�
	LinkNode<T>*current = Loncate(i - 1);
	if (current == nullptr || current->link == nullptr)return false;

	LinkNode<T>*del = Loncate(i);
	current->link = del->link;
	x = del->data;
	delete del;
	return true;
}

template<class T>
void List<T>::output() {
	//������������������
	LinkNode<T>*current = first->link;
	while (current != nullptr) {
		cout << current->data << endl;
		current = current->link;
	}
}

template<class T>
List<T>& List<T>::operator=(List<T>&L) {
	T value;
	LinkNode<T>*srcptr = L.getHead();//�����Ʊ�ĸ���ͷ����ַ
	LinkNode<T>*destptr = first = new LinkNode<T>;//��һ���������ڵ��first����������
	while (srcptr->link!=nullptr)
	{
		value = srcptr->link->data;
		destptr = ->link = new LinkNode<T>(value);
		srcptr = srcptr->link;
		destptr = destptr->link;
	}
	destptr->link= nullptr;
	return *this;//???????????���ز�������
	
}


#if 0
//ǰ�巨����������
template<class T>
void List<T>::inputFront(T endTag) {
	//endTag ���������еĽ�����־
	LinkNode<T>*newNode;
	T value;
	makeEmpty();
	cin >> value;
	while (value != endTag) {
		newNode = new LinkNode<T>(value);
		if (newNode == nullptr) {
			cerr << "�����ڴ�ʧ��" << endl;
		}
		newNode->link = first->link;
		first->link = newNode;
		cin >> value;
	}

}

#endif


//��巨����������
#if 1
template<class T>
void List<T>::inputRear(T endTag) {
#if 0
	LinkNode<T>*newNode;
	T value��
	LinkNode<T>*current = final->link;

	if (newNode == nullptr) {
		cerr << "�����ڴ�ʧ��" << endl;
	}
	while (current != nullptr)
		current = current->link;
	cin >> value;

	newNode = LinkNode<T>(value);
	current->link = newNode;
#endif

	//�̲�
	LinkNode<T>*newNode, *last;
	T val;
	makeEmpty();
	cin >> val;
	last = first;
	while (val != endTag) {
		newNode = new LinkNode<T>(val);
		if (newNode == nullptr) { cerr << "�ڴ����ʧ��" << endl; exit(1); }
		last->link = newNode;
		last = newNode;
		cin >> val;
	}
	last->link = nullptr;
}




#endif