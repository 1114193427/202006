#include<iostream>
using namespace std;

int main()
{int i,j,a[3][3],b[3][3],c[3][3];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
cin>>a[i][j];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
cin>>b[i][j];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
{c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j]+a[i][2]*b[2][j];
cout<<c[i][j]<<" ";
if(j==2)cout<<endl;}
    
    return 0;
}


