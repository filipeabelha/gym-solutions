#include <bits/stdc++.h>

int n, res;
char chr;

int main () {
    scanf("%d", &n);
    scanf("%c", &chr);
    while (scanf("%c", &chr) != EOF) {
        if (chr == 10) {
            printf("%.2lf\n", (double) res/100);
            res = 0;
            continue;
        }
        res++;
    }
    return 0;
}
