#include <bits/stdc++.h>

int abs (int a, int b) {
    return (a-b >= 0) ? a-b : b-a;
}

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int qt, s;
        scanf("%d%d", &qt, &s);
        int nummax = -200;
        int jmax;
        for (int j = 1; j <= qt; j++) {
            int num;
            scanf("%d", &num);
            if (abs(num, s) < abs(nummax, s)) {
                nummax = num;
                jmax = j;
            }
        }
        printf("%d\n", jmax);
    }
    return 0;
}
