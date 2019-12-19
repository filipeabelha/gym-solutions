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

int a[N], b[N], c[N];
int t, n;

int main () {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);
        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            c[i] = b[i]-a[i];
            if (c[i] != 0) {
                if (l == -1) l = i;
                r = i;
            }
        }
        int ok = 1;
        if (l != -1) for (int i = l; i <= r; i++) {
            if (c[i] < 0 or c[i] != c[l]) ok = 0;
        }
        printf("%s\n", ok ? "YES" : "NO");
    }

    return 0;
}
