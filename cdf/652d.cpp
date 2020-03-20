#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

int n;
vector <piii> seg;
map <int, int> id;
vi x;

int bit[N], ans[N];

void add (int p, int v) {
    for (p+=2; p<N; p += p&-p) bit[p] += v;
}

int query (int p) {
    int r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        seg.pb({a, {b, i}});
        x.pb(a);
        x.pb(b);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int i = 0; i < x.size(); i++) id[x[i]] = i+1;

    sort(seg.begin(), seg.end());

    for (auto p : seg) {
        int b = id[p.nd.st];
        add(b, 1);
    }

    for (auto p : seg) {
        int a = p.st;
        int b = id[p.nd.st];
        int i = p.nd.nd;
        add(b, -1);
        ans[i] = query(b);
    }

    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);


    return 0;
}
