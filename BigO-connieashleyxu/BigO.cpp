// BigO.cpp :
// Barrett Koster 2023
// for experimenting with run times
//

#include <iostream>
using namespace std;

void p1(long); // O(n)
void p2(long); // O(n^2)
void p3(long); // O(log(n))
void p4(long); // O(n * log(n))
void p5(long); // O(n!)
void p6(long); // O(n^3)
void p7(long); // O(3^n)
void p8(long); // O(2^n)
void p9(long); // O(1)
const int nfn = 9;
int ping();
long counter;

int main()
{
    cout << "Big O testing\n";

    int pick;
    cout << "pick a number 1 to " << nfn << ": " << endl;
    cin >> pick;
    while (pick != 0)
    {
        long n;
        cout << "enter problem size N = ";
        cin >> n;

        long t1 = time(0);
        counter = 0;
        cout << "t1=" << t1 << endl;

        if (pick == 1)
        {
            p1(n);
        }
        else if (pick == 2)
        {
            p2(n);
        }
        else if (pick == 3)
        {
            p3(n);
        }
        else if (pick == 4)
        {
            p4(n);
        }
        else if (pick == 5)
        {
            p5(n);
        }
        else if (pick == 6)
        {
            p6(n);
        }
        else if (pick == 7)
        {
            p7(n);
        }
        else if (pick == 8)
        {
            p8(n);
        }
        else if (pick == 9)
        {
            p9(n);
        }

        long t2 = time(0);
        long dif = t2 - t1;
        cout << "that took " << dif << " s.\n";
        cout << "operations = " << counter << endl;
        cout << endl;
        cout << "pick another 1 to " << nfn << ": " << endl;
        cin >> pick;
    }
}

/*
do not look below here


no look



no lookie lookie



stop scrolling




no no no no no no no



:-)



*/

void p1(long n)
{
    for (long i = 0; i < n; i++)
    {
        ping();
    }
}
void p2(long n)
{
    for (long i = 0; i < n; i++)
    {
        for (long j = 0; j < n; j++)
        {
            ping();
        }
    }
}
void p3(long n)
{
    ping();
    if (n > 1)
    {
        p3(n / 2);
    }
}
void p4(long n)
{
    if (n <= 1)
    {
        ping();
    }
    else
    {
        p4(n / 2);
        p4(n / 2);
        for (long i = 0; i < n; i++)
        {
            ping();
        }
    }
}

void p5(long n)
{
    if (n <= 0)
    {
        ping();
    }
    else
    {
        for (long i = 0; i < n; i++)
        {
            p5(n - 1);
        }
    }
}

void p6(long n)
{
    for (long i = 0; i < n; i++)
    {
        for (long j = 0; j < n; j++)
        {
            for (long k = 0; k < n; k++)
            {
                ping();
            }
        }
    }
}

void p7(long n)
{
    ping();
    if (n <= 1)
    {
        ping();
    }
    else
    {
        p7(n - 1);
        p7(n - 1);
        p7(n - 1);
    }
}
void p8(long n)
{
    ping();
    if (n <= 1)
    {
        ping();
    }
    else
    {
        p8(n - 1);
        p8(n - 1);
    }
}

void p9(long n) { ping(); }

int ping()
{
    counter++;

    int s = 0;
    /* for (int i = 0; i < 10; i++)
    {
        s += 1;
    }
    */
    return s;
}