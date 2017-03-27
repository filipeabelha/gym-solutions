#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = (1 << 18);

int n, m[20][20], res[20][N];

int dp(int col, int st) {
    if (res[col][st]) return res[col][st];

    int mini = INF;

    for (int i = 0; i < n; i++)
        if ((st & (1 << i)) == 0) {
            int newcol = col+1;
            int newst = st | (1 << i);
            mini = min(mini, m[i][col] + dp(newcol, newst));
        }

    if (mini == INF) return 0;
    else {
        res[col][st] = mini;
        return mini;
    }
}

int main () {
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &m[i][j]);

        memset(res, 0, sizeof(res));

        int ans = dp(0,0);
        printf("%d\n", ans);
    }
    return 0;
}
