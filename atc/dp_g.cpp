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
const int N = 1e5+5;

vi adj[N];
int inc[N], dp[N];

queue <int> q;

int n, m, a, b;

int main () {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        inc[b]++;
    }

    for (int i = 1; i <= n; ++i) if (inc[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u]+1);
            if (inc[v] > 0 and --inc[v] == 0) {
                q.push(v);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans);

    return 0;
}
