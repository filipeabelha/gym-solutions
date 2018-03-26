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

int s, n, ans, els, v[N];

void bk (int i, int t, int m) {
    if (t > s) return;
    if (ans < t) ans = t, els = m;
    for (int j = i+1; j < n; j++)
        bk(j, t+v[j], m|(1 << j));
}

int main () {
    while (~scanf("%d", &s)) {
        ans = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);
        for (int i = 0; i < n; i++) bk(i, v[i], (1 << i));
        for (int i = 0; i < n; i++) if (els & (1 << i)) printf("%d ", v[i]);
        printf("sum:%d\n", ans);
    }
    return 0;
}
