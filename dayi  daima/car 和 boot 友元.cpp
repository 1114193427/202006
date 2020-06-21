#include <iostream>
using namespace std;
//请在这里补充类Boat和Car的定义
class Car;
class Boat
{
public:
    friend int  totalweight(Boat&  b,Car&  c);
    friend class Car;
    Boat (int a)
    {
        weight=a;
    }

private:
    int weight;
};
class Car
{
public:
    friend int  totalweight(Boat&  b,Car&  c);
    Car (int a)
    {
        weight=a;
    }
private:
    int weight;
};

int totalweight(Boat& b,Car& c)
{
    return b.weight+c.weight;
}
int main()
{
    Boat b(100);
    Car c(200);
    cout<<totalweight( b, c)<<endl;
    return 0;
}


