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

int q, k, n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> q;
    while (q--) {
        cin >> n >> k >> s;
        vector <char> ch = {'R', 'G', 'B'};
        vi a(n+1), b(n+1), c(n+1);
        for (int i = 0; i < n; i++) {
            if (s[i] != ch[i%3])     a[i+1]++;
            if (s[i] != ch[(i+1)%3]) b[i+1]++;
            if (s[i] != ch[(i+2)%3]) c[i+1]++;
        }

        for (int i = 1; i < n+1; i++) a[i] += a[i-1];
        for (int i = 1; i < n+1; i++) b[i] += b[i-1];
        for (int i = 1; i < n+1; i++) c[i] += c[i-1];

        int ans = INF;
        for (int i = k; i < n+1; i++) ans = min(ans, a[i]-a[i-k]);
        for (int i = k; i < n+1; i++) ans = min(ans, b[i]-b[i-k]);
        for (int i = k; i < n+1; i++) ans = min(ans, c[i]-c[i-k]);
        printf("%d\n", ans);
    }
    return 0;
}
