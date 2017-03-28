#include <bits/stdc++.h>

int main () {
    long long n;
    scanf("%I64d", &n);
    long long sum = n/2;
    if (n % 2 == 1) sum -= n;
    printf("%I64d\n", sum);
    return 0;
}
