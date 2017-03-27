#include <bits/stdc++.h>

int main () {
        int n;
        while (scanf("%d", &n) != EOF) {
                int matrix[70][70];
                for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) matrix[i][j] = 3;
                for (int i = 0; i < n; i++) matrix[i][i] = 1;
                for (int i = 0; i < n; i++) matrix[n-1-i][i] = 2;
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) printf("%d", matrix[i][j]);
                        printf("\n");
                };
        };
        return 0;
}
