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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;
string s, r;
vector <pair <char, char> > ans;
int cost = 0;
vector <piii> edges;

int par[N], sz[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}

int main () {
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
    scanf("%d ", &n);
    cin >> s >> r;

    for (int i = 0; i < n; i++) if (s[i] != r[i]) edges.pb(mp(1, mp(s[i]-'a', r[i]-'a')));
    sort(edges.begin(), edges.end());

    for (auto e : edges)
        if (find(e.nd.st) != find(e.nd.nd)) {
            unite(e.nd.st, e.nd.nd), cost += e.st;
            ans.pb(mp(e.nd.st+'a', e.nd.nd+'a'));
        }

    printf("%d\n", cost);
    for (auto p : ans) printf("%c %c\n", p.st, p.nd);
    return 0;
}
