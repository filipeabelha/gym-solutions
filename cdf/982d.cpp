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

int n;
pii d[N];

multiset <int> sizes;

int par[N], sz[N], ins[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void ini (int a) {
    par[a] = a;
    sz[a] = 1;
    sizes.insert(1);
}

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    if (sz[a]) sizes.erase(sizes.find(sz[a]));
    if (sz[b]) sizes.erase(sizes.find(sz[b]));
    par[b] = a; sz[a] += sz[b];
    sizes.insert(sz[a]);
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i].st);
        d[i].nd = i;
    }
    sort(d+1, d+1+n);

    int loc = 0;
    int ans = 0;

    for (int j = 1; j <= n; j++) {
        int x = d[j].st;
        int i = d[j].nd;
        ini(i);
        if (ins[i+1]) unite(i, i+1);
        if (ins[i-1]) unite(i, i-1);
        ins[i] = 1;
        if (*sizes.begin() == *sizes.rbegin()) {
            if (loc < sizes.size()) {
                loc = sizes.size();
                ans = x+1;
            }
            if (loc == sizes.size()) {
                ans = min(ans, x+1);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
