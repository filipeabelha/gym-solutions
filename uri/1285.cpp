#include <bits/stdc++.h>

bool rep (int n) {
    int dig[15];
    memset(dig, 0, sizeof(dig));
    while (n > 0) {
        dig[n%10]++;
        n /= 10;
    }
    for (int i = 0; i < 10; i++) if (dig[i] > 1) return true;
    return false;
}


int main () {
    int x, y;
    while (~scanf("%d%d", &x, &y)) {
        int k = 0;
        if (!x and !y) break;
        for (int i = x; i <= y; i++) if (!rep(i)) k++;
        printf("%d\n", k);
    }
    return 0;
}
