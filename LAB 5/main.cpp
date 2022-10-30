#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
void change(ll x, ll y, ll ** a)
{
    ll c[n];
    ll d[n];
    for (int i = 0; i < n; i++)
    {
        c[i] = a[x][i];
        d[i] = a[i][y];
    }
    for (int i = 0; i < n; i++) a[x][i] = d[i];
    for (int i = 0; i < n; i++) a[i][y] = c[i];
    return;
}
int main()
{
    srand(clock());
    cout << "enter size of square matrix" << endl;
    cin >> n;
    ll ** a = new ll * [n];
    for (int i = 0; i < n; i++) a[i] = new ll[n];

    ll usedx[n];
    ll usedy[n];
    for (int i = 0; i < n; i++) usedx[i] = 0;
    for (int i = 0; i < n; i++) usedy[i] = 0;

    cout << "I use numeration from 0" << endl;
    cout << "This is starting matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = (rand() * rand() - 5 * rand() + rand() / 5) % 5;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && i == 0) continue;
            if (a[i][0] == a[0][j] && usedx[i] == 0 && usedy[j] == 0)
            {
                usedx[i] = 1;
                usedy[j] = 1;
                change(i, j, a);
                cout << endl << "change i-th row and j-th column" << endl;
                cout << i << " " << j << endl;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cout << a[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    cout << endl << " This is ending matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
