#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair <int, int> pii;
typedef pair<int, pii> piii;
typedef vector <int> vi;

const int N = 1e3+5;
const int INF = 0x3f3f3f3f;

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};

int tc, n, w, h, x, y;
int dis[N][N];
queue <piii> q;

vi v[N];
vector <pii> u;

bool ok (int d) {
    for (int i = 0; i < N; i++) {
        v[i].clear();
        for (int j = 0; j < N; j++) {
            if (dis[i][j] != INF and dis[i][j] >= d) {
                v[i].pb(j);
            }
        }
    }
    u.clear();
    for (int i = 0; i < N; i++) {
        if (v[i].size())     u.pb({i, v[i][0]});
        if (v[i].size() > 1) u.pb({i, v[i].back()});
    }
    for (int i = 0; i < u.size(); i++) {
        for (int j = i+1; j < u.size(); j++) {
            pii p = u[i];
            pii q = u[j];
            if (abs(p.st-q.st)+abs(p.nd-q.nd) >= d) return true;
        }
    }
    return false;
}

int main () {
    scanf("%d", &tc);
    while (tc--) {
        memset(dis, 63, sizeof dis);
        for (int i = 0; i < N; i++) v[i].clear();

        scanf("%d%d%d", &n, &w, &h);

        if (n == 0) {
            printf("%d\n", w+h-2);
            continue;
        }

        while (n--) {
            scanf("%d%d", &x, &y);
            q.push({0, {x, y}});
        }
        while (q.size()) {
            int d = q.front().st;
            int x = q.front().nd.st;
            int y = q.front().nd.nd;
            q.pop();

            if (dis[x][y] <= d) continue;
            dis[x][y] = d;

            for (int i = 0; i < 4; i++) {
                int a = x+dx[i];
                int b = y+dy[i];
                if (a < 0 or a >= w) continue;
                if (b < 0 or b >= h) continue;
                if (dis[a][b] <= d+1) continue;
                q.push({d+1, {a, b}});
            }
        }

        int l = 1, m, r = 2*N;
        while (l < r) {
            m = (l+r+1)/2;
            if (!ok(m)) r = m-1;
            else l = m;
        }
        printf("%d\n", l);


    }

}
