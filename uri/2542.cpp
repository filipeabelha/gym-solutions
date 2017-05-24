#include <bits/stdc++.h>
using namespace std;

int n, m, l, cm, cl, a, mm[105][105], ll[105][105];

int main () {
    while (~scanf("%d%d%d", &n, &m, &l)) {
        for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) scanf("%d", &mm[i][j]);
        for (int i = 1; i <= l; i++) for (int j = 1; j <= n; j++) scanf("%d", &ll[i][j]);
        scanf("%d%d%d", &cm, &cl, &a);
        printf("%s\n", mm[cm][a] > ll[cl][a] ? "Marcos" : ll[cl][a] > mm[cm][a] ? "Leonardo" : "Empate");
    }
    return 0;
}
