#include <iostream>
using namespace std;
const float pi=3.14159;
class Shape
{
private:
    int m_ID;
public:
    int getID()
    {
        return m_ID;
    }
    void setID(int a)
    {
        m_ID=a;
    }
    int getArea()
    {
        return 0;
    }
    Shape(int a=0)
    {   m_ID=a;
        cout << "Shape constructor called:"<<m_ID << endl;
    }
    ~Shape()
    {
        cout<<"Shape destructor called:"<<m_ID<<endl;
    }
};
class Circle:public Shape
{
private:
    int r;
public:
    int getr() {
        return r;
    }
    void setr(int a) {
        r=a;
    }
    float getArea() {
        return pi*r*r;
    }
    Circle(int a,int b):Shape(b)
    {
        r=a;
        
        cout << "Circle constructor called:" << getID()<<endl;
    }
    ~Circle()
    {
        cout<<"Circle destructor called:"<<getID()<<endl;
    }
};
class Rectangle:public Shape
{
private:
    int h,w;
public:
    int geth() {
        return h;
    }
    int getw() {
        return w;
    }
    void seth(int a) {
        h=a;
    }
    void setw(int a) {
        w=a;
    }
    int getArea()
    {
        return h*w;
    }
    Rectangle(int a,int b,int c):Shape(c)
    {   h=a;
        w=b;
        
        cout << "Rectangle constructor called:"<<getID() << endl;
    }
    ~Rectangle()
    {
        cout<<"Rectangle destructor called:"<<getID()<<endl;
    }
};

int main()
{
    Shape s(1);//1表示ID
    Circle c(4,2);//4表示半径，2表示ID
    Rectangle r(4, 5,3);//4和5表示长和宽，3表示ID
    cout<<"Shape的面积"<<s.getArea()<<endl;
    cout<<"Circle的面积"<<c.getArea()<<endl;
    cout<<"Rectangle的面积"<<r.getArea()<<endl;
}

