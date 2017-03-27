#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int t[15][15];
        for (int j = 1; j <= 9; j+=2) for (int k = 1; k <= j; k+=2)
            scanf("%d", &t[j][k]); 
        for (int j = 1; j <= 7; j+=2) for (int k = 1; k <= j; k+=2) {
            t[j+1][k]   = (t[j][k] + t[j+2][k] - t[j+2][k+2])/2;
            t[j+1][k+1] = (t[j][k] - t[j+2][k] + t[j+2][k+2])/2;
            t[j+2][k+1] = t[j+1][k] - t[j+2][k];
        }
        for (int j = 1; j <= 9; j++) for (int k = 1; k <= j; k++) {
            printf("%d", t[j][k]);
            if (k != j) printf(" "); else printf("\n");
        }
    }
    return 0;
}
