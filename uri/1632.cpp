#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        int res = 1;
        while(1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            if (chr == 'a' or chr == 'A' or chr == 'e' or chr == 'E' or chr == 'i' or chr == 'I' or chr == 'o' or chr == 'O' or chr == 'S' or chr == 's') res *= 3;
            else res *= 2;
        }
        printf("%d\n", res);
    }
    return 0;
}
