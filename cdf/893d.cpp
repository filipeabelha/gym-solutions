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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, d, v[N], u[N], mx[N], sh, bal, ans;

int main () {
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++) u[i] = u[i-1]+v[i];
    mx[n] = u[n];
    for (int i = n-1; i >= 1; i--) mx[i] = max(mx[i+1], u[i]);
    for (int i = 1; i <= n; i++) {
        bal += v[i];
        if (!v[i] and bal < 0) {
            int dep = d-mx[i]-sh;
            if (dep > 0) {
                bal += dep;
                sh += dep;
                if (ans >= 0) ans++;
            } else ans = -1;
        }
        if (bal > d) ans = -1;
        if (!v[i] and bal < 0) ans = -1;
    }
    printf("%d\n", ans);
    return 0;
}
