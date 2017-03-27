#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char chr;
        int h[60];
        int sum = 0;
        int t;
        scanf("%d", &t);
        for (int j = 0; j < t; j++) scanf("%d", &h[j]);
        scanf("%c", &chr);
        for (int j = 0; j < t; j++) {
            scanf("%c", &chr);
            if (chr == 'J' and h[j] > 2) sum++;
            if (chr == 'S' and h[j] <= 2) sum++;
        }
        printf("%d\n", sum);
    }
    return 0;
}
