#include <bits/stdc++.h>
int mtx[105][105];
int mtx2[105][105];
int mtx3[105][105];
int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        int elem;
        scanf("%d", &elem);
        mtx[i][j] = elem;
        mtx2[i][j] = elem;
        mtx3[i][j] = elem;
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        if (!mtx[i][j]) {
            for (int k = 0; k < n; k++) mtx2[k][j] = 0, mtx3[k][j] = 0;
            for (int l = 0; l < m; l++) mtx2[i][l] = 0, mtx3[i][l] = 0;
        }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        if (mtx2[i][j]) {
            for (int k = 0; k < n; k++) mtx3[k][j] = 1;
            for (int l = 0; l < m; l++) mtx3[i][l] = 1;
        }
    bool valid = true;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        if (mtx[i][j] != mtx3[i][j])
            valid = false;
    if (valid) {
        printf("YES\n");
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            printf("%d", mtx2[i][j]);
            if (j != m-1) printf(" ");
            else          printf("\n");
        }
    } else
        printf("NO\n");
    return 0;
}
