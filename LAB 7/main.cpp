#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int min(int k, ...)
{
    int * p = & k;
    p += 2;
    int mn = * p;
    for (; k != 1; k--)
    {
        ++p;
        int now = * (++p);
        if (now < mn) mn = now;
    }
    return mn;
}
double min(double k, ...)
{
    double * p = & k;
    p++;
    double mn = * p;
    for (; k != 1; k--)
    {
        double now = * (++p);
        if (now < mn) mn = now;
    }
    return mn;
}

ll dil(ll a, ll b)
{
    return a / b;
}
complex < double > dil(complex < double > a, complex < double > b)
{
    return a / b;
}

int main()
{
    cout << "TASK1" << endl;
    cout << min(5, 4, 1, 3, 5, 3) << endl;
    cout << min(5.0, 4.1, -1.2, -3.2, 5.56, -3.1) << endl << endl;;
    cout << min(10, 1, 2, 3, 4, -2, 6, 7, 8, 0, 10) << endl;
    cout << min(10.0, 4.3, -4.2, -2.2, 5.56, -4.1, 1.2, 3.0, -10.544, -10.545, 10.0) << endl << endl;
    cout << min(12, -7, 1, 2, -3, 3, 4, -2, 14, 7, 8, 0, 10) << endl;
    cout << min(12.0, 4.3, 4.2, 2.2, 4.56, 4.1, 1.2, 3.0, 100.544, 10.5, 10.0, 6.7, 100.0) << endl << endl;
    cout << "TASK2" << endl;
    complex < double > c1(2.0, 4.0);
    complex < double > c2(1.0, 2.0);
    cout << dil(c1, c2) << endl;
    ll a = 5, b = 3;
    cout << dil(a, b) << endl;;
    return 0;
}
