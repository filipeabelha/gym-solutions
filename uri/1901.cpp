#include <bits/stdc++.h>
using namespace std;

const int N = 2e2+10;
int m[N][N], n, x, y;
set <int> s;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &m[i][j]);
    for (int i = 1; i <= 2*n; i++) scanf("%d%d", &x, &y), s.insert(m[x][y]);
    printf("%d\n", (int) s.size());
    return 0;
}
