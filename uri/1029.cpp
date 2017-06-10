#include <bits/stdc++.h>

int n, ch, f, x;

int fib(int k) {
    ch++;
    if (k == 0 or k == 1) return k;
    else return fib(k-1) + fib(k-2);
}

int main () {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        ch = -1;
        f = fib(x);
        printf("fib(%d) = %d calls = %d\n", x, ch, f);
    }
    return 0;
}
