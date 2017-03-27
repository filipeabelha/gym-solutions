#include <bits/stdc++.h>

int n, m[105][105];

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n+1; i++) for (int j = 0; j < n+1; j++)
        scanf("%d", &m[i][j]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] + m[i+1][j] + m[i][j+1] + m[i+1][j+1] >= 2)
                printf("S");
            else printf("U");
        }
        printf("\n");
    }
    return 0;
}
