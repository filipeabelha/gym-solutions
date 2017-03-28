#include <bits/stdc++.h>

int check (int n, int pos) {
    if (pos % 2 == 1) return pos/2+1;
    else return pos/2 + check (n-pos/2, n-pos/2);
}

int main () {
    int test, n, pos;
    scanf("%d", &test);
    for (int i = 0; i < test; i++) {
        scanf("%d%d", &n, &pos);
        printf("%d\n", check(n, pos));
    }
    return 0;
}
