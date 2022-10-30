#include <stdio.h>


/// an=1/((3n-2)*(3n+1))
int main()
{
    double a, preva, eps, res;
    long long n;
    eps = 0.0001;

    a = 1.0 / 4.0;

    preva = a;

    n = 1;

    res = a;

    while (1)
    {
        if (a < eps) break;

        n++;
        a = preva * (3 * n - 5) / (3 * n + 1);
        printf("%f\n", a);
        res += a;

        preva = a;
    }

    printf("%.10f", res);
    return 0;
}
