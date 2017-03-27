#include <bits/stdc++.h>
using namespace std;

int n, a, b;
char chr;

int main () {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            if (i != 0) printf(" + ");
            scanf("%dx%d", &a, &b);
            a = a*b;
            b -= 1;
            printf("%dx", a);
            if (b > 1) printf("%d", b);
            if (i == n-1) printf("\n");
            scanf("%c", &chr);
            if (chr == 10) break;
            scanf("%c", &chr);
            if (chr == 10) break;
            scanf("%c", &chr);
            if (chr == 10) break;
        }
    }
    return 0;
}
