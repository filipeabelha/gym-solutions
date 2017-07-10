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
const int N = 2e2+5;

int n, m, q;
int t[N][N];

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int x, j = 1; j <= m; j++) {
            scanf("%d", &x);
            if (!x) t[i][j] = 1;
        }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        t[i][j] += t[i-1][j]+t[i][j-1]-t[i-1][j-1];

    scanf("%d", &q);
    for (int x, k = 0; k < q; k++) {
        scanf("%d", &x);
        int ok = 0;
        for (int i = x; i <= n; i++) for (int j = x; j <= m; j++) {
            int qty = t[i][j]-t[i-x][j]-t[i][j-x]+t[i-x][j-x];
            if (!qty) ok = 1;
        }
        printf("%s\n", ok ? "yes" : "no");
    }

    return 0;
}
