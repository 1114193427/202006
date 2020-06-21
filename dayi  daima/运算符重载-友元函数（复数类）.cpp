#include <iostream>
using namespace std;
class Complex
{
private:
    float s;
    float x;
public:
    Complex(float a=0,float b=0)
    {
        s=a;
        x=b;
    }
    void print()
    {
        cout<<"("<<s<<")+("<<x<<"i)";
    }
    friend Complex operator +(Complex c,Complex d);
    friend Complex operator -(Complex c,Complex d);
    friend Complex operator +(Complex d,float c);

    friend Complex operator -(Complex d,float c);

};
Complex operator +(Complex c,Complex d)
{
    return Complex(c.s+d.s,c.x+d.x);
}
Complex operator -(Complex c,Complex d)
{
    return Complex(c.s-d.s,c.x-d.x);
}
Complex operator +(Complex d,float c)
{
    return Complex(d.s+c,d.x);
}
Complex operator -(Complex d,float c)
{
    return Complex(d.s-c,d.x);
}

int main()
{
    Complex a(3,4),b(1,-1),c;
    c=a+b;
    cout<<"a+b=";
    c.print();
    cout<<endl;
    c=a-b;
    cout<<"a-b=";
    c.print();
    cout<<endl;
    c=a+100;
    cout<<"a+100=";
    c.print();
    cout<<endl;
    c=a-2.5;
    cout<<"a-2.5=";
    c.print();
    cout<<endl;
    c=100+a;
    cout<<"100+a=";
    c.print();
    cout<<endl;
    c=2.5-a;
    cout<<"2.5-a=";
    c.print();
    cout<<endl;
    return 0;
}


