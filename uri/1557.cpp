#include <bits/stdc++.h>

using namespace std;

vector <int> matricesOrders;

void buildMatrix(int n, int iFromMain) {
    int matrix[105][105];
    float lastElem = pow(2, 2*n-2);
    int lastElemDigits = 1;
    while (lastElem > 10) lastElem /= 10, lastElemDigits++;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = pow(2, i+j-2);
            printf("%*d", lastElemDigits, matrix[i][j]);
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
