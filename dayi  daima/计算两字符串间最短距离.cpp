#include<iostream>
#include<cmath>
using namespace std;

int main()
{char a[10],b[10];int d,i,j,min=25;
cin>>a;
cin>>b;
for(i=0;a[i]!='\0';i++)
{if(a[i]<='Z'&&a[i]>='A')a[i]+=32;
for(j=0;b[j]!='\0';j++)
{if(b[j]<='Z'&&b[j]>='A')b[j]+=32;
d=abs(a[i]-b[j]);
if(d<min)min=d;}}
cout<<min;
    return 0;
}

