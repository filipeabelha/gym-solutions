#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        int balance = 0, diamonds = 0;
        while (1) {
            scanf("%c", &chr);
            if (chr == 10)
                break;
            if (chr == 60)
                balance++;
            if (chr == 62 and balance > 0)
                balance--,
                diamonds++;
        }
        printf("%d\n", diamonds);
    }
    return 0;
}
