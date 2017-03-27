#include <bits/stdc++.h>

int a, b, c;
int ok;

int main () {
    scanf("%d%d%d", &a, &b, &c);
    if (a == 0 or b == 0 or c == 0) ok = 1;
    if (a == b or a == c or b == c) ok = 1;
    if (a+b==c or a+c==b or b+c==a) ok = 1;
    if (ok) printf("S\n"); else printf("N\n");
    return 0;
}
