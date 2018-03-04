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

int x[N], y[N];
int h, w, q, l, r, d, z;
int v[N];

int main () {
    scanf("%d%d%d", &h, &w, &d);
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) {
            scanf("%d", &z);
            x[z] = i;
            y[z] = j;
        }
    for (int i = 1; i+d < N; i++) {
        v[i+d] = v[i] + abs(x[i]-x[i+d]) + abs(y[i]-y[i+d]);
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &l, &r);
        ll ans = v[r] - v[l];
        printf("%lld\n", ans);
    }
    return 0;
}
