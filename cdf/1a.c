#include <stdio.h>
int main (void)
{
    long long n, m, a;
    scanf("%I64d %I64d %I64d", &n, &m, &a);
    long long sone, stwo;
    if (n%a != 0) sone = n/a + 1; else sone = n/a;
    if (m%a != 0) stwo = m/a + 1; else stwo = m/a;
    printf("%I64d\n", sone * stwo);
    return 0;
}
