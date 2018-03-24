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
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, par[N], vis[N], dist[N], ans = 1;
vi ch[N];

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &par[i]);
        if (par[i] >= 1) ch[par[i]].pb(i);
    }

    queue <int> q;
    for (int i = 1; i <= n; i++) {
        if (par[i] == -1 and !vis[i]) {
            q.push(i);
            dist[i] = 1;
            vis[i] = 1;
            while (q.size()) {
                int v = q.front(); q.pop();
                for (auto u : ch[v]) {
                    vis[u] = 1;
                    dist[u] = dist[v] + 1;
                    ans = max(ans, dist[u]);
                    q.push(u);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
