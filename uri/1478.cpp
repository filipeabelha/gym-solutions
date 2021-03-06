#include <bits/stdc++.h>

using namespace std;

vector <int> matricesOrders;

void buildMatrix(int n, int iFromMain) {
    int matrix[105][105];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = abs(i-j) + 1;
            printf("%3d", matrix[i][j]);
            if (j == n) printf("\n"); else printf(" ");
        }
    }
    printf("\n");
}

int main () {
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        matricesOrders.push_back(n);
    }
    for (int i = 0; i < matricesOrders.size(); i++) buildMatrix(matricesOrders[i], i);
    return 0;
}
