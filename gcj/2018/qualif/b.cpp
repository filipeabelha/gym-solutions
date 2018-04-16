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

int tc, n;

int main () {
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        printf("Case #%d: ", t);
        scanf("%d", &n);
        vi v(n);
        for (auto& x : v) scanf("%d", &x);

        vi a, b;
        for (int i = 0; i < v.size(); i += 2) a.pb(v[i]);
        for (int i = 1; i < v.size(); i += 2) b.pb(v[i]);

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        v.clear();
        for (int i = 0; i < b.size(); i++) {
            v.pb(a[i]);
            v.pb(b[i]);
        }
        if (n&1) v.pb(a.back());

        int ok = 1;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] < v[i-1]) {
                printf("%d\n", i-1);
                ok = 0;
                break;
            }
        }
        if (ok) printf("OK\n");
    }
    return 0;
}
