#include <iostream>
#include <cmath>
using namespace std;
int isPrime(unsigned short a)
{int i;
if(a==1) return 0;
if(a==2) return 1;
for(i=2;i<a;i++)
if(a%i==0) return 0;
else return 1;}

int main()
{
    unsigned short a;
    cin>>a;
    if (isPrime(a))
        cout<<"Y"<<endl;
    else
        cout<<"N"<<endl;
}

