#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 5e2+5;

int n, m, t, a[N][N], vis[N][N];

int dx[] = {+1, -1, +0, +0};
int dy[] = {+0, +0, +1, -1};

int ok () {
    cl(vis, 0);

    queue <piii> q;
    if (a[1][1]-1-t >= 0) {
        q.push({1, {1, 1}});
        vis[1][1] = 1;
    }

    while (q.size()) {
        int k = q.front().st;
        int x = q.front().nd.st;
        int y = q.front().nd.nd;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int K = k+1;
            int X = x+dx[i];
            int Y = y+dy[i];
            if (X < 1 or X > n) continue;
            if (Y < 1 or Y > m) continue;
            if (vis[X][Y]) continue;
            if (a[X][Y]-K-t < 0) continue;

            q.push({K, {X, Y}});
            vis[X][Y] = 1;
        }
    }

    return vis[n][m];
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }

    int l = -INF, m, r = INF;

    while (l < r) {
        t = m = (l+r+1)/2;
        if (!ok()) r = m-1;
        else       l = m;
    }

    printf("%d\n", max(l, -1));

    return 0;
}
