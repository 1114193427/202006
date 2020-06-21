#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

template <typename T>
class Array
{
//请完成类的设计
public:
    Array(int n)
    {
    vector<T> v(n);
    }
    void input(int n)
    {
        int i;T j;
        for (i = 0; i < n; i++)
            {
			cin >> j;
            v.push_back(j);}
    }
    T &operator[](int i)
    {
        return v[i];
    }

private:
    vector<T>v;




};



class Fract
{
//请完成类的设计
public:
    Fract() {}
    Fract(int n1, int m1) : m(m1), n(n1)
    {
        int c = 0;
        if (m * n < 0)
            c = 1;
        m = fabs(m);
        n = fabs(n);
        int a = m > n ? n : m;
        for (int i = a; i >= 2; i--)
        {
            if ((m % i == 0) && (n % i == 0))
            {
                m = m / i;
                n = n / i;
            }
        }
        if (c)
            n = -n;
    }
    void show()

    {

        if (m == 1 || n == 0)

            cout << n << endl;

        else

            cout << n << "/" << m << endl;
    }
    Fract operator+=(const Fract &f)
    {
        int m1, n1;
        m1 = m * f.m;
        n1 = n * f.m + f.n * m;
        Fract *p;
        p = new Fract(n1, m1);
        n = p->getn();
        m = p->getm();
        delete p;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const Fract &f);
    friend istream &operator>>(istream &is, Fract &f)
    {
        is >> f.n >> f.m;
        return is;
    }
    int getn() const { return n; }
    int getm() const { return m; }

private:
    int m;
    int n;




};


int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for (unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}


