#include <iostream>
#include <string>
using namespace std;

class CStudent
{
private:
    int age;
    string name;
    static int count;
public:
    CStudent()
    {   count++;
        name="noname";
        cout<<name<<" is contructing"<<endl;
    }
    CStudent(string a,int b)
    {   name=a;
        age=b;
        count++;
        cout<<name<<" is contructing"<<endl;
    }
    ~CStudent()
    {count--;
    cout<<name<<" is destructing"<<endl;}
    static int getcount()
    {
        return count;
    }
    void printname()
    {
        cout<<"name:"<<name<<endl;
    }

};
//请在这里初始静态成员变量
int CStudent::count=0;


int main()
{
	cout << "现在有学生" << CStudent::getcount() << endl;
	{
		CStudent stuB[5];
		stuB[4].printname();
		cout << "现在有学生" << CStudent::getcount() << endl;
	}
	cout << "现在有学生" << CStudent::getcount() << endl;
	{
		CStudent stuA[2] = {CStudent("Tom", 3), CStudent("Jerry", 2)};
		for (int i = 0; i < 2; i++)
		{
			stuA[i].printname();
		}
		cout << "现在有学生" << CStudent::getcount() << endl;
	}
	cout << "现在有学生" << CStudent::getcount() << endl;

	return 0;
}

