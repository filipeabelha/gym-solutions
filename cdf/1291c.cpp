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

int t, n, m, k, v[N];

int main () {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
        }

        k = min(k, m-1);

        int ans = 0;

        for (int l = 1, r = n-k; r <= n; l++, r++) {
            int cur = INF;
            for (int L = l, R = l+n-m; R <= r; L++, R++) {
                cur = min(cur, max(v[L], v[R]));
            }
            ans = max(ans, cur);
        }
        printf("%d\n", ans);
    }

    return 0;
}
