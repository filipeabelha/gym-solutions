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
#define _ << " " <<
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

vector <pair <int, pair<string, ld> > > v;
int n;
string s, t, u;
ld a, b, c, d;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--) {
        cin >> s >> u >> t >> a >> b >> c >> d;
        ld k = (3*b - 2*c)*d/(3*b);
        k *= 1*(t[0] == 'P') + 1.5*(t[0] == 'G') + 2*(t[0]=='U');
        k *= 2*(u[0] == 'S') + 2*(u[0] == 'F') + 1.5*(u[0] == 'P') + 
             1.5*(u[0] == 'B') + 1*(u[0]=='N');
        ld p = (k < 255 ? (int) k/255. : 1);
        v.pb({a, {s, p}});
    }
    sort(v.begin(), v.end());
    cout << setprecision(10);
    for (auto p : v) cout << p.st _ p.nd.st _ p.nd.nd << endl;

    return 0;
}
