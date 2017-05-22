#include <bits/stdc++.h>

int a, b, c, ok;

int main () {
    scanf("%d%d%d", &a, &b, &c);
    if (a == b or a == c or b == c) ok = 1;
    if (a+b==c or a+c==b or b+c==a) ok = 1;
    printf("%s\n", ok ? "S" : "N");
    return 0;
}
