#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int ins[105];
        memset(ins, 0, sizeof(ins));
        int p = 0;
        int x;
        scanf("%d", &x);
        char chr;
        scanf("%c", &chr);
        for (int j = 1; j <= x; j++) {
            scanf("%c", &chr);
            if (chr == 'L') {
                p--;
                ins[j] = -1;
                while (chr != 10) scanf("%c", &chr);
            } else if (chr == 'R') {
                p++;
                ins[j] = 1;
                while (chr != 10) scanf("%c", &chr);
            } else {
                int k;
                scanf("AME AS %d", &k);
                p += ins[k];
                ins[j] = ins[k];
                while (chr != 10) scanf("%c", &chr);
            }
        }
        printf("%d\n", p);
    }
    return 0;
}
