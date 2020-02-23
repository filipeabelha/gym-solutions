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
const int N = 1e3+5;

int t, n, ans[N];

int main () {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        cl(ans, 0);

        set <int> s;
        for (int i = 1; i <= 2*n; i++) s.insert(i);

        vi v(n);
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            s.erase(x);
            v[i] = x;
            ans[2*i] = x;
        }

        int ok = 1;
        for (int i = 0; i < n; i++) {
            int x = v[i];

            if (s.empty()) {
                ok = 0;
                break;
            }

            auto it = s.lower_bound(x);

            if (it == s.end()) {
                ok = 0;
                break;
            }

            int y = *it;
            s.erase(y);

            if (y < x) {
                ok = 0;
                break;
            }

            ans[2*i+1] = y;
        }

        if (ok) {
            for (int i = 0; i < 2*n; i++) printf("%d%c", ans[i], " \n"[i==(2*n-1)]);
        } else printf("-1\n");

    }

    return 0;
}
