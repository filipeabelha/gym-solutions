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

int t;

int main () {
    scanf("%d", &t);
    while (t--) {
        vi v(3);
        scanf("%d%d%d", &v[0], &v[1], &v[2]);
        sort(v.begin(), v.end());
        int& a = v[2];
        int& b = v[1];
        int& c = v[0];

        int ans = 0;
        if (a) ans++, a--;
        if (b) ans++, b--;
        if (c) ans++, c--;
        if (a and b) ans++, a--, b--;
        if (a and c) ans++, a--, c--;
        if (b and c) ans++, b--, c--;
        if (a and b and c) ans++, a--, b--, c--;
        printf("%d\n", ans);
    }

    return 0;
}
