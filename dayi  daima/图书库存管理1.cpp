#include <iostream>
using namespace std;
class Book
{
//请在此处补充Book类的定义

private:
    unsigned int m_ID;//编号

    string m_Name;//书名

    string m_Introduction;//简介

    string m_Author;//作者

    string m_Date;//日期

    unsigned int m_Page;//页数
public:
    void SetID(int a)
    {
        m_ID=a;
    }
    void SetName(string b)
    {
        m_Name=b;
    }
    void SetIntroduction(string e)
    {
        m_Introduction=e;
    }
    void SetAuthor(string c)
    {
        m_Author=c;
    }
    void SetPage(unsigned int d)
    {
        m_Page=d;
    }
    void SetDate(string f)
    {
        m_Date=f;
    }
     int GetID()
    {
        return m_ID;
    }
    string GetName()
    {
        return m_Name;
    }
    string GetAuthor()
    {
        return m_Author;
    }
    string GetIntroduction()
    {
        return m_Introduction;
    }
    int GetPage()
    {
        return m_Page;
    }
    string GetDate()
    {
        return m_Date;
    }
    Book()
    {
        m_ID=0;
    }
    virtual ~Book() {;}
    Book(const Book& other)
    {   m_Page=other.m_Page;
        m_ID=other.m_ID;
        m_Name=other.m_Name;
        m_Introduction=other.m_Introduction;
        m_Author=other.m_Author;
        m_Date=other.m_Date;
    }

};
//请在此处补充Book类的成员函数实现

class Store
{
//请在此处补充Store类的定义
private:
    Book *m_pBook;//指向利用new操作动态创建的Book数组

    unsigned int m_Count;//表示库存中图书的数量
public:
    unsigned int GetCount()
    {
        return m_Count;
    }
    void SetCount(unsigned int a)
    {
        m_Count=a;
    }
    Store()
    {   m_Count=0;
        m_pBook=0;
        cout << "Store default constructor called!" << endl;
    }
    Store(int n)
    {   m_Count=n;
        m_pBook=new Book[n];
        cout << "Store constructor with (int"<< n<<") called!" << endl;
    }
    virtual ~Store()
    {   m_Count=0;
        if(m_pBook!=0)delete []m_pBook;
        cout << "Store destructor called!"<< endl;
    }
    Store(const Store& other)
    {   m_Count=other.m_Count;
        m_pBook=other.m_pBook;
        cout << "Store copy constructor called!" << endl;
    }
    void in(Book &b)
    {   int i;
        Book *p=new Book[m_Count+1];
        for(i=0; i<m_Count; i++)
            p[i]=m_pBook[i];
        p[m_Count]=b;
        m_Count++;
        delete []m_pBook;
        m_pBook=p;
    }
    void out(string name)
    {   int i,j;
        Book *p=new Book[m_Count-1];
        for(i=0,j=0; j<m_Count-1; i++,j++)
        {   if(m_pBook[i].GetName()==name)i++;
            p[j]=m_pBook[i];
        }
        m_Count--;
        delete []m_pBook;
        m_pBook=p;
    }
    Book findbyID(int ID)
    {   int i;
        for(i=0; i<m_Count; i++)
            if(m_pBook[i].GetID()==ID) return m_pBook[i];
    }
    Book findbyName(string name)
    {   int i;
        for(i=0; i<m_Count; i++)
            if(m_pBook[i].GetName()==name)return m_pBook[i];
        if(i==m_Count)return Book();
    }
    void printList()
    {   int i;
        cout<<"There are totally "<<m_Count<<" Books:"<<endl;
        for(i=0; i<m_Count; i++)
        {   cout<<"ID="<<m_pBook[i].GetID()<<";  ";
            cout<<"Name:"<<m_pBook[i].GetName()<<";  ";
            cout<<"Author:"<<m_pBook[i].GetAuthor()<<";  ";
            cout<<"Date:"<<m_pBook[i].GetDate()<<";  "<<endl;
        }
    }

};
//请在此处补充Store类的成员函数实现

int main()
{
    Store s;
    Book b1,b2,b3;
    b1.SetID(1);
    b1.SetName("C++ 语言程序设计(第4版)");
    b1.SetAuthor("郑莉");
    b1.SetIntroduction("介绍C++及面向对象的知识");
    b1.SetDate("201007");
    b1.SetPage(529);
    b2.SetID(2);
    b2.SetName("离散数学");
    b2.SetAuthor("左孝凌");
    b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
    b2.SetDate("198209");
    b2.SetPage(305);
    b3.SetID(3);
    b3.SetName("c程序设计");
    b3.SetAuthor("谭浩强");
    b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
    b3.SetDate("201006");
    b3.SetPage(355);

    cout<<"第一本书入库"<<endl;
    s.in(b1);
    cout<<"第二本书入库"<<endl;
    s.in(b2);
    cout<<"第三本书入库"<<endl;
    s.in(b3);
    cout <<"现有库存书籍数量："<<s.GetCount() << endl;
    cout <<"查找并出库图书：离散数学" << endl;
    Book tmpbook=s.findbyName("离散数学");
    if(tmpbook.GetID()!=0)
    {
        s.out("离散数学");
        cout <<"离散数学 已成功出库" << endl;
    }
    else
        cout<<"没有找到name为离散数学的书"<<endl;
    cout <<"现有库存书籍数量："<<s.GetCount() << endl;

    cout <<"查找图书 ID：3" << endl;
    tmpbook=s.findbyID(3);
    if(tmpbook.GetID()!=0)
        cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl;
    else
        cout<<"没有找到ID为"<<3<<"的书"<<endl;

    cout <<"查找图书 name：离散数学" << endl;
    tmpbook=s.findbyName("离散数学");
    if(tmpbook.GetID()!=0)
        cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl;
    else
        cout<<"没有找到name为离散数学的书"<<endl;

    cout<<"输出所有库存图书的信息"<<endl;
    s.printList();
    cout<<"程序运行结束"<<endl;
    return 0;
}


