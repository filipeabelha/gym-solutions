#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int m[N][65], tc, n, num, el, op, a, b, inter;

int main () {
    scanf("%d", &tc); for (int t = 1; t <= tc; t++) {
        scanf("%d", &n); for (int i = 1; i <= n; i++) {
            scanf("%d", &num);
            for (int j = 0; j < num; j++) scanf("%d", &el), m[i][el] = t;
            m[i][0] = 0;
            for (int j = 1; j <= 60; j++) if (m[i][j] == t) m[i][0]++;
        }
        scanf("%d", &n); for (int i = 1; i <= n; i++) {
            inter = 0;
            scanf("%d%d%d", &op, &a, &b);
            for (int j = 1; j <= 60; j++)
                if (m[a][j] == t and m[b][j] == t) inter++;
            printf("%d\n", op == 1 ? inter : m[a][0]+m[b][0]-inter);
        }
    }
    return 0;
}
