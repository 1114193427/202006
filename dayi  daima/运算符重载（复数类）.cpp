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
    {   cout<<s<<"+"<<x<<"i";}
        Complex operator +(Complex c)
        {   Complex d;
            d.s=c.s+s;
            d.x=c.x+x;
            return Complex(d.s,d.x);
        }
        Complex operator -(Complex c)
        {   Complex d;
            d.s=s-c.s;
            d.x=x-c.x;
            return Complex(d.s,d.x);
        }
        Complex operator +(float c)
        {   Complex d;
            d.s=c+s;
            d.x=x;
            return Complex(d.s,d.x);
        }
        Complex operator -(float c)
        {   Complex d;
            d.s=s-c;
            d.x=x;
            return Complex(d.s,d.x);
        }
        };



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

    return 0;
}


