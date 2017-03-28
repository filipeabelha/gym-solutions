#include <bits/stdc++.h>

int main () {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int ans = 0;
    if (c == 0) {if (a == b) ans = 1;}
    else if ((b-a) % c == 0) if ((b-a)/c >= 0) ans = 1;
    if (ans) printf("YES\n"); else printf("NO\n");
    return 0;
}
