#include <bits/stdc++.h>

char chr;
int n;

int main () {
    while (1) {
        scanf("%c", &chr);
        if (chr == 10) break;
        n++;
    }
    if (n > 80) printf("NO\n");
    else printf("YES\n");
    return 0;
}
