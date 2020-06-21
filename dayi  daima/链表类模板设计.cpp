#include <iostream>
#include <iomanip>
using namespace std;

template<class T>

struct node
  {  T data;
    node<T>* next;  
};
template<class T>
class linkedList
{
public:
    linkedList();//构造函数
    virtual ~linkedList();//析构函数，注意要链表中所有节点的资源
    void insert( T value );//警告：必须初始化才能使用！
    bool initiate();//初始化单链表，使用new操作创建头结点。如果创建失败，则返回false，否则返回true
    bool isEmpty();//判断单链表是否为空
    //删除单链表中第pos个元素结点，并将删除的节点的值存在value中。
    //注意：如果链表为空、删除位置大于链表长度、以及删除位置为0的情况，需要终止删除并输出相应信息
    bool remove( int pos, T& value );
    void print();//顺序打印单链表，如果是单链表为空，则输出 Empty
    int Length();//返回单链表长度。如果是单链表为空，则返回-1
private:
    node<T>* head;
    int len;
};

//请在此处补充所有成员函数的实现
template<class T>
linkedList<T>::linkedList()
{
    head=NULL;
    len=0;
}
template<class T>
linkedList<T>::~linkedList()
{
delete head;}
template<class T>
bool linkedList<T>::initiate()
{  if( head=new node<T>)
    {
        head->next=NULL;
        return true;
    }
    else return false;
}
template<class T>
void linkedList<T>::insert(T value)
{   node<T> *p=new node<T>;
p->data=value;p->next=NULL;
node<T> *q=head;
    while(q->next!=NULL)
    {q=q->next;}
   q->next=p;
    len++;
}
template<class T>
int linkedList<T>::Length()
{   if(isEmpty())return -1;
    return len;
}
template<class T>
bool linkedList<T>::remove(int pos,T &val)
{if(pos<=0) {cout<<"pos <= 0, failed"<<endl;return false;}
if(pos>len){cout<<"pos > len, failed"<<endl;return false;}
int i;node<T>* q,*p;
p=head->next;q=head;
for(i=1;i<pos;i++)
{p=p->next;
q=q->next;}
q->next=p->next;
val=p->data;
delete p;len--;return true;
}
template<class T>
bool linkedList<T>::isEmpty()
{
        if(head==NULL||head->next==NULL) return true;
        else return false;
}







template<class T>
void linkedList<T>::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    node<T>* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}





int main(int argc, char* argv[])
{
    linkedList<int> L1;
    int n;
    int val;
    //初始化链表
    if(!L1.initiate())
        return 0;

    cin>>n;//输入链表中数据个数
    for(int i=0; i<n; i++) //输入n个数，并插入链表
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：" ;
    L1.print();//打印链表

    cin>>n;//输入需要删除的数据的位置
    if (L1.remove(n,val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length：" << L1.Length()<< endl;//输出链表长度
        cout<< "data：" ;
        L1.print();//打印链表
    }

    return 0;
}



