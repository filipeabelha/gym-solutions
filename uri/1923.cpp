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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e3+5;

map <string, int> id;
map <int, string> idrev;
string a, b;
int cnt, n, g;
int vis[N];
vi adj[N];
queue <pii> q;
set <string> s;

int main () {
    scanf("%d%d", &n, &g);
    id["Rerisson"] = ++cnt;
    idrev[1] = "Rerisson";
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (!id.count(a)) id[a] = ++cnt, idrev[id[a]] = a;
        if (!id.count(b)) id[b] = ++cnt, idrev[id[b]] = b;
        adj[id[a]].pb(id[b]);
        adj[id[b]].pb(id[a]);
    }
    q.push(mp(1, 0));
    vis[1] = 1;
    while (!q.empty()) {
        int u = q.front().st;
        int d = q.front().nd;
        q.pop();
        for (auto v : adj[u]) {
            if (!vis[v] and d < g) {
                vis[v] = 1;
                s.insert(idrev[v]);
                q.push(mp(v, d+1));
            }
        }
    }
    printf("%d\n", (int) s.size());
    for (auto x : s) printf("%s\n", x.c_str());
    return 0;
}
