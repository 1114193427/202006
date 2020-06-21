#include <iostream>
#include <iomanip>
using namespace std;
//请在此处补充Account类的定义
class Account
{
public:
    void init (char a[],char b[],char e[],int c,float d)
    {   int i;
        for(i=0; i<18; i++)
            zh[i]=a[i];
        for(i=0; b[i]!='\0'; i++)
            name[i]=b[i];
        age=c;
        for(i=0; i<4; i++)
            xb[i]=e[i];
        if(100*d-(int)(100*d)>0.1) {
            cout << "您输入的金额不合法" << endl;
            money=0;
        }
        else money=d;
    }
    void printmoney()
    {
        cout<<fixed<<setprecision(2);
        cout<<name<<"的存款为"<<money<<endl;
    }
    void deposit(float a)
    {   if(100*a-(int)(100*a)>0)cout<<"您输入的金额不合法"<<endl;
        else
            money+=a;
    }
    void withdraw(float a)
    {   if(100*a-(int)(100*a)>0.1)cout<<"您输入的金额不合法"<<endl;
        else if(money-a<0)cout<<"您的存款金额不足"<<endl;
        else money-=a;
    }
private:
    char zh[18];
    char name[16];
    char xb[4];
    int age;
    float money;
};


int main()
{
    Account tom;
    tom.init("32020320011001876X", "Tom Black", "男", 19, 2000.89);
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(89.471);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(10000);
    tom.printmoney();//输出：Tom Black的存款为12000.89
    tom.withdraw(10001);
    tom.printmoney();//输出：Tom Black的存款为1999.89
    tom.withdraw(10000.123);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom Black的存款为1999.89
    tom.withdraw(10000.9);//输出：您的存款金额不足
    tom.printmoney();//输出：Tom Black的存款为1999.89
    Account jerry;
    jerry.init("320203200910116569", "Jerry Black", "女", 11, 100.956);//输出：您输入的金额不合法
    jerry.printmoney();//输出：Jerry Black的存款为0.00
}

