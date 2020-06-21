#include<iostream>
using namespace std;

int main()
{char b[8];int i,s=0,m,flag=0;
for(i=0;i<8;i++)
cin>>b[i];
for(i=0;i<8;i++)
{if(b[i]=='*') m=i;s=s+b[i];}
b[m]=36+48*8+42-s;
for(i=0;i<8;i++)
if((m-i)==(b[m]-b[i]))flag++;
if(flag%2==1)cout<<b[m];
else cout<<"No Answer";
    return 0;
}


