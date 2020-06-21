#include "iostream"
using namespace std;

class vehicle
{
private:
    int maxspeed,weight;
public:
    void run()
    {
        cout<<"vehicle run"<<endl;
    }
    void stop()
    {
        cout<<"vehicle stop"<<endl;
    }
    vehicle(int a=0,int b=0)
    {   maxspeed=a,weight=b;
        cout<<"vehicle constructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
    }

    ~vehicle()
    {
        cout<<"vehicle destructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
    }
};
class bicycle:virtual public vehicle
{
private:
    int height;
public:
    bicycle(int a=0)
    {height=a;
        cout<<"bicycle constructor called. height:"<<height<<endl;
    }
    ~bicycle()
    {
        cout<<"bicycle destructor called. height:"<<height<<endl;
    }
};
class motorcar:virtual public vehicle
{private:
int seatnum;
public:
motorcar(int a=0)
{seatnum=a;
cout << "motorcar constructor called. seatnum:" <<seatnum<< endl;}
~motorcar()
{cout<<"motorcar destructor called. seatnum:"<<seatnum<<endl;}
};
class motorcycle:public bicycle,public motorcar
{public:
motorcycle(int a,int b,int c,int d):vehicle(c,d),bicycle(a),motorcar(b)
{
cout<<"motorcycle constructor called"<<endl;}
~motorcycle()
{cout<<"motorcycle destructor called"<<endl;}
};


int main(int argc, char *argv[])
{
    motorcycle m(1, 2, 3, 4);//1表示height，2表示setnum，3表示maxspeed，4表示weight
    m.run();
    m.stop();
    return 0;
}

