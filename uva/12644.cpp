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
const int N = 5e2+5;
const int M = 50;

string s;
int n, m, f[M], g[M], b[N], vis[N], ans, x;
vector <string> u, v;
vi adj[N];

bool chk (string s, string t) {
    cl (f, 0);
    cl (g, 0);
    for (auto c : s) f[c-'a']++;
    for (auto c : t) g[c-'a']++;
    for (auto c : s) if (f[c-'a'] > g[c-'a']) return false;
    return true;
}

bool match (int i) {
    if (vis[i] == x) return false;
    vis[i] = x;
    for (auto j : adj[i])
        if (!b[j] or match(b[j])) return b[j] = i;
    return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m) {
        u.clear();
        v.clear();
        cl(vis, 0);
        cl(b, 0);
        for (int i = 0; i < N; i++) adj[i].clear();
        ans = x = 0;
        while (n--) cin >> s, v.pb(s);
        while (m--) cin >> s, u.pb(s);

        for (int i = 1; i <= u.size(); i++)
            for (int j = 1; j <= v.size(); j++)
                if (chk(u[i-1], v[j-1])) adj[i].pb(j);

        for (int i = 1; i <= u.size(); i++) x++, ans += match(i);

        printf("%d\n", ans);
    }
    return 0;
}
