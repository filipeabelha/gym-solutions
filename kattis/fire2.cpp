#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair <int, int> pii;
typedef pair <pii, pii> P;

const int N = 1e3+5;
const int INF = 0x3f3f3f3f;

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};

int t[N][N], a, b, ans;
queue <P> q;

void add (int k, int d, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int X = x+dx[i];
        int Y = y+dy[i];
        if (k <= t[X][Y]) continue;
        if (k == 1 and (X < 1 or X > a)) {
            ans = min(ans, d+1);
            continue;
        }
        if (k == 1 and (Y < 1 or Y > b)) {
            ans = min(ans, d+1);
            continue;
        }
        if (X < 1 or X > a) continue;
        if (Y < 1 or Y > b) continue;
        q.push({{k, d+1}, {X, Y}});
    }
}

int main () {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        memset(t, 0, sizeof t);
        ans = INF;

        scanf("%d%d", &b, &a);

        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= b; j++) {
                char c;
                scanf(" %c", &c);
                if (c == '#') t[i][j] = 3;
                if (c == '*') t[i][j] = 2;
                if (c == '@') t[i][j] = 1;
            }

        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= b; j++)
                if (t[i][j] == 2) add(2, 0, i, j);

        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= b; j++)
                if (t[i][j] == 1) add(1, 0, i, j);

        while (q.size()) {
            P p = q.front(); q.pop();

            int k = p.st.st;
            int d = p.st.nd;
            int x = p.nd.st;
            int y = p.nd.nd;

            if (k < t[x][y]) continue;
            t[x][y] = k;

            add(k, d, x, y);
        }

        if (ans == INF) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);

    }
    return 0;
}
