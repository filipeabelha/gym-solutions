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

ll n, m, u[N], v[N], bst = -LINF, ans = -LINF, ind;

int main () {
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < n; i++) scanf("%lld", &u[i]);
    for (int i = 0; i < m; i++) scanf("%lld", &v[i]);

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        if (bst < u[i]*v[j]) {
            bst = u[i]*v[j];
            ind = i;
        }

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        if (i != ind and ans < u[i]*v[j])
            ans = u[i]*v[j];

    printf("%lld\n", ans);
    return 0;
}
