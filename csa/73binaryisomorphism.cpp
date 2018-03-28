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

int t, n;
vi a[N], b[N];

int ok (int x, int y) {
    if (!a[x].size() and !b[y].size()) return 1;
    if (a[x].size() != b[y].size()) return 0;
    if (a[x].size() == 1 and b[y].size() == 1) return ok(a[x][0], b[y][0]);
    return (ok(a[x][0], b[y][0]) and ok(a[x][1], b[y][1])) or
           (ok(a[x][0], b[y][1]) and ok(a[x][1], b[y][0]));
}

int x;

int main () {
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < N; i++) a[i].clear(), b[i].clear();
        scanf("%d", &n);

        int u, v;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (x == 0) u = i;
            else a[x].pb(i);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (x == 0) v = i;
            else b[x].pb(i);
        }
        printf("%d\n", ok(u, v));
    }
    return 0;
}
