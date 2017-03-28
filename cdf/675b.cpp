#include <bits/stdc++.h>

int maxi (int x, int y) {
    return (x > y) ? x : y;
}

int mini (int x, int y) {
    return (x < y) ? x : y;
}

int main () {
    int n, a, b, c, d;
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (mini(mini(i+a-d, i+b-c), i+a+b-c-d) >= 1 and maxi(maxi(i+a-d, i+b-c), i+a+b-c-d) <= n) count++;
    printf("%I64d\n", (long long) n*count);
    return 0;
}
