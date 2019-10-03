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

ll x, y, xf, yf, n, o, dx[N], dy[N];
map <pll, ll> vis;
string s;

bool ok (ll m) {
    ll X = x + (m/n)*dx[n] + dx[m%n];
    ll Y = y + (m/n)*dy[n] + dy[m%n];
    return abs(xf-X) + abs(yf-Y) <= m;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> y >> xf >> yf >> n >> s;
    for (int i = 1; i <= s.size(); i++) {
        dy[i] = dy[i-1] + (s[i-1] == 'U') - (s[i-1] == 'D');
        dx[i] = dx[i-1] + (s[i-1] == 'R') - (s[i-1] == 'L');
    }

    ll l = 0, m, r = LINF;
    while (l < r) {
        m = (l+r)/2;
        if (!ok(m)) l = m+1;
        else r = m;
    }

    cout << (l > LINF/2 ? -1 : l) << endl;

    return 0;
}
