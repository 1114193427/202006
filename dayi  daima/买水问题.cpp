#include<iostream>
using namespace std;

int main()
{int n,m,s,t;
cin>>n;
t=n;m=n;s=n;
while(n!=0)

{n=t/2+m/3;
s=s+n;
t=n+t%2;
m=n+m%3;}

    cout << s;
    return 0;
}

