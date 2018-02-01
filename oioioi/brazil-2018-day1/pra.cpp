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
const int N = 2e6+5;

struct line {
    long long l, r, i;
};

vector <line> v;
line lin;
int n, k, goodi;
bitset <N> ans;
vi a;

ll l, z;
priority_queue <pii> r;

int main () {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &lin.l, &lin.r);
        lin.i = i+1;
        v.pb(lin);
    }

    sort(v.begin(), v.end(), [](line a, line b) { return (a.l == b.l ? a.r > b.r : a.l < b.l); });

    for (int i = 0; i < k; i++) {
        l = v[i].l;
        r.push(mp(-v[i].r, v[i].i));
    }

    z = -r.top().st-l;
    goodi = k-1;

    for (int i = k; i < v.size(); i++) {
        l = v[i].l;
        r.push(mp(-v[i].r, v[i].i));
        r.pop();
        if (-r.top().st-l > z) {
           z = -r.top().st-l;
           goodi = i;
        }
    }

    ans.reset();

    for (int i = 0; i < k; i++) {
        ans[v[i].i] = 1;
        l = v[i].l;
        r.push(mp(-v[i].r, v[i].i));
    }

    for (int i = k; i <= goodi; i++) {
        ans[v[i].i] = 1;
        l = v[i].l;
        r.push(mp(-v[i].r, v[i].i));

        ans[r.top().nd] = 0;
        r.pop();
    }

    printf("%lld\n", z);
    for (int i = 0; i < N; i++) if (ans[i]) a.pb(i);
    for (int i = 0; i < a.size(); i++) printf("%d%c", a[i], " \n"[i+1 == (int)a.size()]);
    return 0;
}
