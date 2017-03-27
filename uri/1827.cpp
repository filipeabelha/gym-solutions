#include <bits/stdc++.h>

using namespace std;

void buildMatrix(int n) {
    int matrix[105][105];
    memset(matrix, 0, sizeof(matrix));
    int third = n/3;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) matrix[i][j] = 2;
            if (i == n-j+1) matrix[i][j] = 3;
            if (i > third and i <= n-third and j > third and j <= n-third) matrix[i][j] = 1;
            if (i == n/2+1 and j == n/2+1) matrix[i][j] = 4;
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main () {
    int n;
    while (scanf("%d", &n) != EOF) buildMatrix(n);
    return 0;
}
