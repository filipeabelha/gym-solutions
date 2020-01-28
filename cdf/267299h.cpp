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
const int N = 2e5+5;

vi s, p;
int b[N], n, m;

void kmppre() {
    m = p.size();

    b[0] = -1;
    for (int i = 0, j = -1; i < m; b[++i] = ++j)
        while (j >= 0 and p[i] != p[j])
            j = b[j];
}

bool kmp() {
    n = s.size();
    for (int i = 0, j = 0; i < n;) {
        while (j >= 0 and s[i] != p[j]) j = b[j];
        i++, j++;
        if (j == m) return true;
    }
    return false;
}

int adjust (int x) {
    int mod = 360000;
    return ((x%mod)+mod)%mod;
}

int main () {
    scanf("%d", &n);
    s.resize(n);
    p.resize(n);

    for (int i = 0; i < n; i++) scanf("%d", &s[i]);
    sort(s.begin(), s.end());
    vi z = s;
    for (int i = 1; i < n; i++) z[i] = adjust(s[i]-s[i-1]);
    z[0] = adjust(s[0]-s.back());
    s = z;

    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    sort(p.begin(), p.end());
    z = p;
    for (int i = 1; i < n; i++) z[i] = adjust(p[i]-p[i-1]);
    z[0] = adjust(p[0]-p.back());
    p = z;

    for (int i = 0; i < n; i++) s.pb(s[i]);

    kmppre();
    printf("%s\n", kmp() ? "possible" : "impossible");

    return 0;
}
