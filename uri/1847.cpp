#include <bits/stdc++.h>

int main () {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == b) {if (b < c) {printf(":)\n"); return 0;} else {printf(":(\n"); return 0;}}
    if (a > b) {if ( (a - b) <= (b - c) ) {printf(":(\n"); return 0;} else {printf(":)\n"); return 0;}}
    if (a < b) if ((c - b) >= (b - a)) printf(":)\n"); else printf(":(\n");
    return 0;
}
