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

ll n, c[N], ans[N][2];
string s;
vector <string> v[2];

int main () {
    ios_base::sync_with_stdio(false);
    cl(ans, 63);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    v[0].pb("foo");
    v[1].pb("bar");
    for (int i = 1; i <= n; i++) {
        cin >> s;
        v[0].pb(s);
        reverse(s.begin(), s.end());
        v[1].pb(s);
    }
    ans[1][0] = 0;
    ans[1][1] = c[1];
    for (int i = 2; i <= n; i++) {
        if (v[0][i] >= v[0][i-1]) {
            ans[i][0] = ans[i-1][0];
        }

        if (v[1][i] >= v[1][i-1]) {
            ans[i][1] = ans[i-1][1] + c[i];
        }

        if (v[0][i] >= v[1][i-1]) {
            ans[i][0] = min(ans[i][0], ans[i-1][1]);
        }

        if (v[1][i] >= v[0][i-1]) {
            ans[i][1] = min(ans[i][1], ans[i-1][0] + c[i]);
        }
    }
    cout << (min(ans[n][0], ans[n][1]) >= LINF ? -1 : min(ans[n][0], ans[n][1])) << endl;
    return 0;
}
