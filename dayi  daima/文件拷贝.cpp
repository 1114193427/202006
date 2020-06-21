#include<iostream>
#include<fstream>
using namespace std;
int main()
{float c[20],t;int i=0,j,n;
    ifstream f1("a.txt");
    ofstream f2("b.txt");
    while(f1.good())
    {
	
	f1>>c[i];
	i++;
	}

    f1.close();
	n=i;
	for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
	if(c[j]<c[i])
	{t=c[j];
	c[j]=c[i];
	c[i]=t;
	
	}
	for(i=0;i<n;i++)
	f2<<c[i]<<" ";
	f2.close();
    return 0;
}


