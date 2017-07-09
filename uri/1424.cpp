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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

int n, q;
int f[N];
map <pii, int> m;

int main () {
    while (~scanf("%d%d", &n, &q)) {
        cl(f, 0);
        m.clear();
        for (int x, i = 1; i <= n; i++) {
            scanf("%d", &x);
            f[x]++;
            m[mp(f[x], x)] = i;
        }
        for (int a, b, i = 0; i < q; i++) {
            scanf("%d%d", &a, &b);
            printf("%d\n", m[mp(a, b)]);
        }
    }
    return 0;
}
