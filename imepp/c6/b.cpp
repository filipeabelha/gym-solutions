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
const int N = 2e5+5;

int par[N], sz[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

int n, m, q, x, cnt;
string s, t;

map <string, int> id;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;

    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (!id.count(s)) {
            cnt += 2;
            id[s] = cnt;
        }
    }
    while (m--) {
        cin >> x >> s >> t;
        int a = id[s];
        int b = id[t];

        if (x == 1) {
            if (find(a) != find(b+1)) {
                unite(a, b);
                unite(a+1, b+1);
                printf("YES\n");
            } else printf("NO\n");
        }

        if (x == 2) {
            if (find(a) != find(b)) {
                unite(a, b+1);
                unite(a+1, b);
                printf("YES\n");
            } else printf("NO\n");
        }
    }

    while (q--) {
        cin >> s >> t;
        int a = id[s];
        int b = id[t];
        if      (find(a) == find(b)) printf("1\n");
        else if (find(a+1) == find(b)) printf("2\n");
        else printf("3\n");
    }

    return 0;
}
