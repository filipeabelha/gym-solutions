#include <bits/stdc++.h>

long long fact(int n) {
        if (n == 0 or n == 1) return 1;
        else return n*fact(n-1);
}

int main () {
        int n1, n2;
        while (scanf("%d %d", &n1, &n2) != EOF) {
                printf("%lld\n", fact(n1)+fact(n2));
        }
        return 0;
}
