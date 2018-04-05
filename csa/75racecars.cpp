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
typedef pair <ld, int> P;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, x, y, d[N], v[N];

ld a[N], b[N], c[N];

vector <P> ta, tb;

int main () {
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &d[i], &v[i]);
        a[i] = (ld) d[i]/v[i];
        b[i] = (ld) d[i]/(v[i]-y);
        c[i] = (ld) d[i]/(v[i]+x);

        ta.pb({a[i], i});
        tb.pb({b[i], i});
    }

    sort(ta.begin(), ta.end());
    sort(tb.begin(), tb.end());

    for (int i = 1; i <= n; i++) {
        P pa = {a[i], i};
        P pb = {c[i], i};

        int pos1 = lower_bound(ta.begin(), ta.end(), pb) - ta.begin();
        int pos2 = lower_bound(tb.begin(), tb.end(), pa) - tb.begin();

        printf("%d\n", min(pos1, pos2)+1);
    }

    return 0;
}
