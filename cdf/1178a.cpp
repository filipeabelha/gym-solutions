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

int n, x, s, z, k;
vi ans;
vector <pii> v;

int main () {
    scanf("%d%d", &n, &x);
    s = x;
    k = x;
    ans.pb(1);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &z);
        v.pb({z, i});
        s += z;
        if (2*z <= x) {
            k += z;
            ans.pb(i);
        }
    }
    if (2*k <= s) printf("0\n");
    else {
        printf("%d\n", (int) ans.size());
        for (auto x : ans) printf("%d ", x);
        printf("\n");
    }

    return 0;
}
