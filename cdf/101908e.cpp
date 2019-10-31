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

string s, t;
int f[N], n, x, ok, ans[N];
vi d[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;

    cl(d, 63);

    n = t.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) ok = 1;
        d[t[i]].pb(n-i-1);
    }
    for (int i = n; i < s.size(); i++) {
        int dis = s.size()-i-1;
        db(i _ s[i] _ d[s[i]] _ dis);
        if (d[s[i]] <= dis) ans[dis] = f[s[i]];
    }

    for (int i = 0; i < N; i++) if (ans[i]) ok++;
    cout << ok << endl;

    return 0;
}
