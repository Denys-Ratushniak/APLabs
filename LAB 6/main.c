#include <stdio.h>

#include <stdlib.h>

int main()
{
    char s[256];
    gets(s);
    int n = 0;
    int now = 9;
    n = strlen(s);
    int kilkch[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < n; i++)
        if (s[i] >= '0' && s[i] <= '9') kilkch[s[i] - '0']++;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            while (kilkch[now] == 0) now--;
            s[i] = now + '0';
            kilkch[now]--;
        }
    }
    puts(s);
    return 0;
}
