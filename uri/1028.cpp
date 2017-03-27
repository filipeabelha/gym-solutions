#include <bits/stdc++.h>

int mdc (int a, int b) {
        if (a % b == 0) return b; else return mdc(b,a%b);
}

int main () {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            printf("%d\n", mdc(n1, n2));
        }
        return 0;
}
