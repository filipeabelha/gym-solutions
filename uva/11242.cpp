#include <bits/stdc++.h>
using namespace std;

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
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, m;

int main () {
    while (~scanf("%d", &n) and n) {
        scanf("%d", &m);

        vector <ld> s;
        vi v(n), w(m);
        for (auto& x : v) scanf("%d", &x);
        for (auto& x : w) scanf("%d", &x);
        for (auto x : v) for (auto y : w) s.pb((ld)y/x);
        sort(s.begin(), s.end());

        ld ans = 0;
        for (int i = 1; i < s.size(); i++) ans = max(ans, s[i]/s[i-1]);

        printf("%.2Lf\n", ans);
    }
    return 0;
}
