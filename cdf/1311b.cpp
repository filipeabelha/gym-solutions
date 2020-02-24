#include <bits/stdc++.h>
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int t, x, ok[N];

int main () {
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vi a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        cl(ok, 0);
        for (int i = 0; i < m; i++) {
            int x;
            scanf("%d", &x);
            ok[x-1] = 1;
        }

        vi b = a;
        sort(b.begin(), b.end());

        int ans = 1;
        for (int i = 0; i < n; i++) if (!ok[i]) {
            multiset <int> p, q;
            for (int j = 0; j <= i; j++) {
                p.insert(a[j]);
                q.insert(b[j]);
            }

            if (p != q) ans = 0;
        }

        printf("%s\n", ans ? "YES" : "NO");

    }

    return 0;
}
