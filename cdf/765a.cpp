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

int n;
string s, t, a, b;
map <string, int> m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    while (n--) {
        cin >> t;
        a.clear();
        a += t[0];
        a += t[1];
        a += t[2];

        b.clear();
        b += t[5];
        b += t[6];
        b += t[7];

        if (a != s) m[a]++;
        if (b != s) m[b]++;
    }

    int ok = 1;
    for (auto p : m) if (p.nd&1) ok = 0;

    cout << (ok ? "home" : "contest") << endl;

    return 0;
}
