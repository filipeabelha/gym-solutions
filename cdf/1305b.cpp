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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

string s;
int a[N], b[N], ok[N], no[N], ans;
vll z;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int k = 0;
    int cnt = s.size();
    int n = s.size();
    while (cnt) {
        cl(a, 0);
        cl(b, 0);
        cl(ok, 0);
        cl(no, 0);
        ans = 0;

        for (int i = 1; i <= n; i++) a[i] = a[i-1] + (s[i-1] == '(');
        for (int i = n; i >= 1; i--) b[i] = b[i+1] + (s[i-1] == ')');

        for (int i = 1; i <= n; i++) ans = max(ans, min(a[i], b[i]));
        if (ans == 0) break;

        k++;
        int x = ans, y = ans;
        for (int i = 1; i <= n; i++) if (s[i-1] == '(' and x > 0) ok[i] = 1, x--;
        for (int i = n; i >= 1; i--) if (s[i-1] == ')' and y > 0 and x == 0) ok[i] = 1, y--;

        vl v;
        for (int i = 1; i <= n; i++) if (ok[i]) v.pb(i);
        for (int i = 1; i <= n; i++) {
            if (no[i]) continue;
            if (ok[i]) no[i] = 1, s[i-1] = 0, cnt--;
        }
        z.pb(v);
    }
    printf("%d\n", (int) z.size());
    for (auto& v : z) {
        printf("%d\n", (int) v.size());
        for (auto x : v) printf("%lld ", x);
        printf("\n");
    }


    return 0;
}
