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
const int N = 1e6+5;

string s;
ll w[N], u[N], ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int n = s.size();
    if (s[0] == 'v' and s[1] == 'v') w[1] = 1;
    for (int i = 2; i < n; i++) {
        w[i] = w[i-1] + (s[i] == 'v' and s[i-1] == 'v');
    }

    if (s[n-1] == 'v' and s[n-2] == 'v') u[n-2] = 1;
    for (int i = n-3; i >= 0; i--) {
        u[i] = u[i+1] + (s[i] == 'v' and s[i+1] == 'v');
    }

    for (int i = 1; i < n-1; i++) {
        ans += (s[i] == 'o')*w[i-1]*u[i+1];
    }

    cout << ans << endl;
    return 0;
}
