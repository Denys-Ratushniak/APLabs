#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef long long ll;
long long sum(long long k, ...)
{
    long long * p = & k;
    long long s = 0;
    for (; k != 0; k--)
        s += * (++p);
    return s;
}

int main()
{
    long long z = sum(3, 2, 3, 4);
    printf("%lld", z);
    return 0;
}
