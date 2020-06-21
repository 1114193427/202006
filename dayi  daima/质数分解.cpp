#include <iostream>
#include <cmath>
using namespace std;

//判断是否为素数
int isPrime(long num)
{
int i;
if(num==2) return 1;
for(i=2;i<num;i++)
if(num%i==0) return 0;
if(i==num)return 1;

}

//计算质因素分解，
void factorization(long n,long a[],int &b
)
{
int i;

for(i=2;n!=1;i++)
if(n%i==0){n=n/i;a[b]=i;b++;i=1;}

    return;
}

int main()
{
    long n;
    long factor[100];
    int numofFactor = 0;
    cin >> n;
    factorization(n, factor, numofFactor);
    for (int i = 0; i < numofFactor; i++)
    {
        cout << factor[i] << " ";
    }
    cout << endl;
    return 0;
}

