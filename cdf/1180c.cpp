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
const int N = 3e5+5;

int n, q, x, mx = -INF, cnt, k;
ll y;
pii ans[N];
deque <int> d;

int main () {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        d.push_back(x);
        mx = max(mx, x);
    }
    for (int i = 1; i <= 3*n; i++) {
        int a = d.front(); d.pop_front();
        int b = d.front(); d.pop_front();
        ans[i] = {a, b};
        d.push_front(max(a, b));
        d.push_back(min(a, b));
        if (k == 0 and d.front() == mx) {
            k = i;
        }
    }

    while (q--) {
        scanf("%lld", &y);
        if (y > k+n)  {
            y -= (k+n);
            y %= n-1;
            y += (k+n);
        }
        printf("%d %d\n", ans[y].st, ans[y].nd);
    }

    return 0;
}
