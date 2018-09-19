#include"LinkedList.h"

template<class T>
List<T>::List(List<T>&L) {
	//List is a single Link;
	//我的版本，只进行值的复制
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

	//教材版本
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
}

template<class T>
 void List<T>::makeEmpty() {
#if 0
	 //自己的版本
#endif

	 LinkNode<T>*q;
	 while (first->link != nullptr) {
		 q = first->link;
		 first->link = q->link;//first指向第二个结点；
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
	 //课本版本
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
	 //带附加头结点的Search()
#if 0
	 //自己版本
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
	 //定位函数,返回表中第i个元素的地址
	 if (i < 0)return nullptr;
	 LinkNode<T>*current = first;
	 int k = 0;
	 while (current != nullptr&&k < i) {
		 current = current->link;
		 k++;
	 }
	 return current;//返回第i个结点的地址，若返回null，表示i值太大
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

	 //课本
 if (i <= 0)return nullptr;
	 LinkNode<T>*current = Loncate(i);
	 if (current = nullptr)return false;//i值taida
	 else { x = current->data; return true; }

 };


template<class T>
void List<T>::setData(int i, T& x) {
	//给链表第i个值赋值x
	if (i <= 0)return;
	LinkNode<T>*current = Loncate(i);
	if (current == nullptr)return;
	current->data = x;
	
}

template<class T>
bool List<T>::Insert(int i, T&x) {
	//将新元素x插在第i个结点之后。
#if 0
	if (i <= 0)return false;
	LinkNode<T>*current = Loncate(i);
	if (current == nullptr)return false;
	LinkNode<T>*NewNode = new LinkNode<T>(x);
	p->link = current->link;
	current->link = p;
	return true;
#endif
	//课本
	LinkNode<T>*current = Loncate(i);
	if (current == false)return false;
	LinkNode<T>*newNode = new LinkNode<t>(x);
	if (newNode == nullptr)cerr << "存储分配错误！" << endl;
	newNode->link = current->link;
	current->link = newNode;
	return true;
}

template<class T>
bool List<T>::Remove(int i, T& x) {
	//删除掉第i个元素
#if 0
	if (i < 0)return false;
	LinkNode<T>*current = Loncate(i-1);
	LinkNode<T>*de = Loncate(i);
	current->link = de->link;
	x = de->data;
	delete de;
	return true;
#endif
	//教材
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
	//输出单链表的所有数据
	LinkNode<T>*current = first->link;
	while (current != nullptr) {
		cout << current->data << endl;
		current = current->link;
	}
}

template<class T>
List<T>& List<T>::operator=(List<T>&L) {
	T value;
	LinkNode<T>*srcptr = L.getHead();//被复制表的附加头结点地址
	LinkNode<T>*destptr = first = new LinkNode<T>;//这一步操作将节点和first链接起来；
	while (srcptr->link!=nullptr)
	{
		value = srcptr->link->data;
		destptr = ->link = new LinkNode<T>(value);
		srcptr = srcptr->link;
		destptr = destptr->link;
	}
	destptr->link= nullptr;
	return *this;//???????????返回操作对象
	
}


#if 0
//前插法建立单链表
template<class T>
void List<T>::inputFront(T endTag) {
	//endTag 是输入序列的结束标志
	LinkNode<T>*newNode;
	T value;
	makeEmpty();
	cin >> value;
	while (value != endTag) {
		newNode = new LinkNode<T>(value);
		if (newNode == nullptr) {
			cerr << "分配内存失败" << endl;
		}
		newNode->link = first->link;
		first->link = newNode;
		cin >> value;
	}

}

#endif


//后插法建立单链表
#if 1
template<class T>
void List<T>::inputRear(T endTag) {
#if 0
	LinkNode<T>*newNode;
	T value；
	LinkNode<T>*current = final->link;

	if (newNode == nullptr) {
		cerr << "分配内存失败" << endl;
	}
	while (current != nullptr)
		current = current->link;
	cin >> value;

	newNode = LinkNode<T>(value);
	current->link = newNode;
#endif

	//教材
	LinkNode<T>*newNode, *last;
	T val;
	makeEmpty();
	cin >> val;
	last = first;
	while (val != endTag) {
		newNode = new LinkNode<T>(val);
		if (newNode == nullptr) { cerr << "内存分配失败" << endl; exit(1); }
		last->link = newNode;
		last = newNode;
		cin >> val;
	}
	last->link = nullptr;
}




#endif