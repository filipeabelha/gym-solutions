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

const int INF = 0x3f3f3f3f, MOD = 1e4, EPS = 1e-6, N = 1e2+10;

int n, l, s, t, a, b, c, d, m[N][N][5], v[N], ans[N];

int mult (int x) {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++)
            m[i][j][2] += (m[i][k][x] * m[k][j][0]) % MOD;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        m[i][j][x] = m[i][j][2] % MOD, m[i][j][2] = 0;
}

int main () {
    while (~scanf("%d%d", &n, &l)) {
        scanf("%d%d", &s, &t);
        cl(m, 0); cl(v, 0); cl(ans, 0);
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
            if (i == j) m[i][j][1] = 1;
        v[s] = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            // m0 = base matrix
            // m1 = ans matrix
            // m2 = aux matrix
            m[a][i][0]++;
            m[b][i][0]++;
            m[c][i][0]++;
            m[d][i][0]++;
        }
        while (l) {
            if (l&1) mult(1);
            mult(0);
            l /= 2;
        }
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
            ans[i] += m[i][j][1] * v[j];
        printf("%d\n", ans[t]);
    }
    return 0;
}
