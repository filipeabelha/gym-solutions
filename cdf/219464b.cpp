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
typedef pair<ll ,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll f1, a, b, c, m, n, z;
map <ll, ll> freq;
vector <pll> stk, f, ans;
pll p;

int main () {
    scanf("%lld%lld%lld%lld", &f1, &a, &b, &c);
    f.pb(mp(f1, 0));
    scanf("%lld%lld", &m, &n);
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
        scanf("%lld", &z);
        freq[z]++;
    }
    for (pll p : freq) stk.pb(mp(p.nd, p.st));
    printf("%d\n", (int) stk.size());
    for (int i = 1; i < (int) stk.size(); i++) {
        ll newf = (a*f.back().st+b)%c+1;
        f.pb(mp(newf, i));
    }
    sort(f.begin(), f.end());
    sort(stk.begin(), stk.end());
    for (int i = 0; i < (int) stk.size(); i++)
        ans.pb(mp(f[i].nd, stk[i].nd));
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int) stk.size(); i++)
        printf("%lld ", ans[i].nd);
    printf("\n");

    return 0;
}
