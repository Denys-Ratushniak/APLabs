#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
ld f[31];
int main()
{
    f[0] = 1;
    for (ll i = 1; i <= 28; i++) f[i] = f[i - 1] * i;
    ld a = 0.1;
    ld b = 1.0;
    ll n = 1;
    ld eps = 0.0001;
    for (ld x = a; x <= b; x += (b - a) / 10.0)
    {
        ld sn, se;
        sn = 1.0;
        se = 1.0;
        for (ll i = 1; i <= n; i++) sn += (ld) pow(-1, i) * (ld) pow(x, 2 * i) / (ld) f[2 * i];

        ld a = 0;
        ll i = 1;

        while (1)
        {
            a = (ld) pow(-1, i) * (ld) pow(x, 2 * i) / (ld) f[2 * i];
            se += a;
            i++;
            if (abs(a) < eps) break;
        }

        cout << fixed << setprecision(7) << x << " " << sn << " " << se << " " << cos(x) << " " << endl;
    }
    return 0;
}
