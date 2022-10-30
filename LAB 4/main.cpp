#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    srand(clock());
    ll mas[101];
    ll sz;
    cout << "enter the size of the array" << endl;
    cin >> sz;
    for (int i = 0; i < sz; i++)
    {
        mas[i] = rand() % 10;
        cout << mas[i] << " ";
    }
    cout << endl;
    for (int i = sz - 1; i >= 0; i--)
    {
        if (mas[i] == 0)
        {
            for (int j = i + 1; j < sz; j++) swap(mas[j], mas[j - 1]);
            sz--;
            break;
        }
    }
    for (int i = 0; i < sz; i++) cout << mas[i] << " ";
    cout << endl;
    cout << "enter position" << endl;
    ll pos;
    cin >> pos;
    if (pos > sz)
    {
        for (int i = 0; i < sz; i++) cout << mas[i] << " ";
        return 0;
    }
    sz++;
    for (int i = sz; i > pos; i--) swap(mas[i], mas[i - 1]);
    mas[pos] = 100;
    for (int i = 0; i < sz; i++) cout << mas[i] << " ";
    cout << endl;
    return 0;
}
