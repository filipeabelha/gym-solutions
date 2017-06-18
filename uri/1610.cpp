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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e4+10;

vector <set <int> > adj(N);
int inc[N], tc, n, e, a, b, ans;
queue<int> q;

int main () {
    scanf("%d", &tc); while (tc--) {
        for (int i = 0; i < N; i++) adj[i].clear();
        cl(inc, 0);
        ans = 0;
        scanf("%d%d", &n, &e);
        for (int i = 0; i < e; i++) {
            scanf("%d%d", &a, &b);
            if (!adj[b].count(a)) adj[b].insert(a), inc[a]++;
        }
        for (int i = 1; i <= n; ++i) if (!inc[i]) q.push(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            ans++;
            for (int v : adj[u])
                if (inc[v] > 0 and !(--inc[v]))
                    q.push(v);
        }
        printf("%s\n", ans == n ? "NAO" : "SIM");
    }
    return 0;
}
