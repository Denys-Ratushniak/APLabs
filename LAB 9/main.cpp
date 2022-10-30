#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    FILE * fin, * fout;
    if ((fin = fopen("F1.txt", "rt")) == 0) exit(0);
    if ((fout = fopen("F2.txt", "wt+")) == 0) exit(1);
    char buf[512];
    char * ptr;
    ll f = 0;
    ll c = 0;
    ll z = 0;
    while ((ptr = fgets(buf, sizeof(buf), fin)) != NULL)
    {
        if ( * ptr != 'A')
        {
            fputs(buf, fout);
            char * k = ptr;
            z = 0;
            while ( * k != NULL)
            {
                k++;
                z++;
            }
            if (z == 1) continue;
            if (f == 0)
            {
                while ( * ptr == ' ' && * ptr != NULL)
                {
                    ptr++;
                }
                while ( * ptr != NULL && * ptr != ' ')
                {
                    c++;
                    ++ptr;
                }
                ptr++;
                if ( * ptr == NULL) c--;
                f = 1;
            }
        }
    }
    cout << c << endl;
    return 0;
}
