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

int t, n;

int main () {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vi v(n), mini(n);
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);
        if (n) mini[n-1] = v[n-1];
        for (int i = n-2; i >= 0; i--) mini[i] = min(mini[i+1], v[i]);
        int ans = 0;
        for (int i = n-2; i >= 0; i--) ans += (mini[i+1] < v[i]);
        printf("%d\n", ans);
    }

    return 0;
}
