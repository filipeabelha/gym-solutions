#include <bits/stdc++.h>
using namespace std;

char a[30];
char chr;
int n, x, brk;

int main () {
    while (1) {
        for (int i = 1; i <= 26; i++) {
            if (scanf("%c", &chr) == EOF) {
                brk = 1;
                break;
            }
            a[i] = chr;
        }
        if (brk) break;
        scanf("%d", &n);
        while (n--) {
            scanf("%d%c", &x, &chr);
            printf("%c", a[x]);
            if (!n) printf("\n");
        }
    }
    return 0;
}
