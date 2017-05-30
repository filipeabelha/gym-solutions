#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e5+10;

int o, d, k, z, ans, vis[N], p[N];
priority_queue <pii> pq;

void go (int dep, int x) {
    if (x == d) {
        ans = dep;
        while (!pq.empty()) pq.pop();
        return;
    }
    int dx[] = {x+1, x-1, 2*x, 3*x, x/2};
    int ilim = 5;
    if (x&1) ilim = 4;
    for (int i = 0; i < ilim; i++) {
        int y = dx[i];
        if (y <= 1e5 and y > 0 and !vis[y] and !p[y])
            pq.push(mp(-dep-1, -y)), vis[y] = 1;
    }

    while (!pq.empty()) {
        int u = -pq.top().st;
        int v = -pq.top().nd; pq.pop();
        go(u, v);
    }
}

int main () {
    while (1) {
        scanf("%d%d%d", &o, &d, &k);
        if (!o and !d and !k) break;
        cl(p, 0); cl(vis, 0); ans = -1;
        while (k--) scanf("%d", &z), p[z] = 1;
        go (0, o);
        printf("%d\n", ans);
    }
    return 0;
}
