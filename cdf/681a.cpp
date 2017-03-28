#include <bits/stdc++.h>

int n, a, b, yes;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char name[20];
        scanf(" %s %d %d", name, &a, &b);
        if (b >= 2400 and a >= 2400 and b > a)
            yes = 1;
    }
    if (yes) printf("YES\n");
    else printf("NO\n");
    return 0;
}
