#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

vi v;
int n, x, bit[N];
ll ans;

void add (int p, int v) {
    for (; p < N; p += p&-p) bit[p] += v;
}

int qry (int p) {
    int r = 0;
    for (; p; p -= p&-p) r += bit[p];
    return r;
}

int main () {
    while (~scanf("%d", &n)) {
        v.clear();
        ans = 0;
        cl(bit, 0);

        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            v.pb(x);
        }
        reverse(v.begin(), v.end());
        for (auto k : v) {
            ans += qry(N-k);
            add(N-k, 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
