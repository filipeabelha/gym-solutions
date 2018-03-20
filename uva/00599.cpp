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
const int N = 50;

int t, vis[N];
string s;
char a, b;
vi adj[N], pts;
int x, y;

void dfs (int i) {
    if (vis[i]) return;
    vis[i] = 1;
    for (auto j : adj[i]) dfs(j);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    cin.ignore();
    while (t--) {
        for (int i = 0; i < N; i++) adj[i].clear();
        pts.clear();
        cl(vis, 0);
        x = y = 0;

        while (1) {
            getline(cin, s);
            if (s[0] == '*') break;
            sscanf(s.c_str(), "(%c,%c)", &a, &b);
            int w = a-'A';
            int z = b-'A';
            adj[w].pb(z);
            adj[z].pb(w);
        }
        getline(cin, s);
        for (int i = 0; i < s.size(); i += 2) {
            sscanf(s.c_str()+i, "%c%c", &a, &b);
            int w = a-'A';
            pts.pb(w);
            if (b == '\n') break;
        }
        for (int p : pts) {
            if (!vis[p] and adj[p].empty()) {
                vis[p] = 1;
                y++;
                continue;
            }
            if (!vis[p]) {
                x++;
                dfs(p);
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n", x, y);
    }
    return 0;
}
