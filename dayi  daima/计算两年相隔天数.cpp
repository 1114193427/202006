#include <iostream>
#include<iostream>
#include<cmath>
using namespace std;
int leapyear(int year)
{   if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}
int monthday(int year,int month)
{   switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 2:
        if (leapyear(year))
            return 29;
        else
            return 28;
        break;
    default:
        return 30;
        break;
    }
}


class CTime
{
private:
    int n,y,r,x,f,m;
public:
    CTime(int year,int month,int day,int hour=0,int minute=0,int second=0)
    {   int f1=0,f2=0;
        n=year;
        y=month;
        r=day;
        x=hour;
        f=minute;
        m=second;

        if(y<1||y>12)f1=1;
        if(r>monthday(n,y))f1=1;
        if(x>23||f>59||m>59)f2=1;
        if(f1||f2)n=y=r=x=f=m=0;
        if(f1&&!f2)cout << "date error!" << endl;
        if(f2&&!f1)cout << "time error!" << endl;
        if(f2&&f1)cout << "date and time error!" << endl;
        cout << "构造函数被调用" << endl;
    }

    CTime(CTime &p)
    {   n=p.n;
        y=p.y;
        r=p.r;
        x=p.x;
        f=p.f;
        m=p.m;
        cout << "拷贝构造函数被调用" << endl;
    }
    ~CTime()
    {
        cout<<"析构函数被调用"<<endl;
    }
    int dayDiff(CTime t)
    {   int i,s1=0,s2=0,d;
        for(i=1; i<t.y; i++)
            s1=s1+monthday(t.n,i);
        for(i=1; i<y; i++)
            s2=s2+monthday(n,i);
        d=(n-t.n)*365+(n-t.n)/4+s2+r-s1-t.r;
        return abs(d);
    }
    void showTime()
    {
        cout <<n<< "/" <<y<<"/"<<r<<" "<<x<<":"<<f<<":"<<m<< endl;
    }
    int isvalid()
    {   if(n==0)return 0;
        else return 1;
    }
};


int main()
{
    int year, month, day, hour, minute, second;
    cin >> year >> month >> day >> hour >> minute >> second;
    CTime t1(year, month, day, hour, minute, second);
    t1.showTime();
    CTime t2(2000, 1, 1); //利用默认形参将时间初始化为00:00:00
    if (t1.isvalid())     //如果日期和时间合法，则计算天数
    {
        int days=0;
        days=t1.dayDiff(t2);
        cout << "这两天之间相隔了" << days << "天" << endl;
        days=t2.dayDiff(t1);
        cout << "这两天之间相隔了" << days << "天" << endl;
    }
}

