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

set <int> adj[N];
int inc[N];
queue <int> q;
vi tsort;
int n, e, a, b;

int main () {
    while (~scanf("%d%d", &n, &e) and n) {
        for (int i = 0; i < N; i++) adj[i].clear();
        cl(inc, 0);
        tsort.clear();

        while (e--) {
            scanf("%d%d", &a, &b);
            if (!adj[a].count(b)) {
                adj[a].insert(b);
                inc[b]++;
            }
        }

        for (int i = 1; i <= n; i++) if (!inc[i]) q.push(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u])
                if (inc[v] > 0 and !(--inc[v]))
                    q.push(v);
            tsort.pb(u);
        }

        for (int i = 0; i < tsort.size(); i++)
            printf("%d%c", tsort[i], " \n"[i+1==tsort.size()]);
    }
    return 0;
}
