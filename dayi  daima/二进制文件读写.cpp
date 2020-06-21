#include<iostream>
#include<fstream>
using namespace std;
int main()
{
struct student
{
short stu_id,score;
};
int n,i;
cin>>n;
struct student* a=new struct student[n];
struct student* b=new struct student[n];
for(i=0;i<n;i++)
{cin>>a[i].stu_id;
cin>>a[i].score;
}
ofstream f("out.txt",ios::binary);
f.write((char*)a,n*sizeof(struct student));
f.close();
ifstream f1("out.txt",ios::binary);
f1.read((char*)b,n*sizeof(struct student));
for(i=0;i<n;i++)
{
cout<<b[i].stu_id;
cout<<b[i].score;}
f1.close();
ofstream f2("out.txt",ios::app);
f2.write((char*)a,n*sizeof(struct student));
return 0;
}


