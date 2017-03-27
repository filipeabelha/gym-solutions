#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", x%2==0?x/2:x/2+1);
    }
    return 0;
}
