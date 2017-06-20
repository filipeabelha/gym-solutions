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

const int INF = 0x3f3f3f3f, MOD = 1e6, EPS = 1e-6;

ll n, k, l;
ll m[3][2][2], aux[2][2];

void mult (int x, int y) {
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
        for (int z = 0; z < 2; z++)
            aux[i][j] += (m[x][i][z]*m[y][z][j]) % MOD;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            m[x][i][j] = aux[i][j] % MOD, aux[i][j] = 0;
}

int main () {
    while (~scanf("%lld%lld%lld", &n, &k, &l)) {
        n /= 5;

        // Init matrix
        m[0][0][0] = 1; m[0][0][1] = k%MOD;
        m[0][1][0] = 0; m[0][1][1] = 0;

        // Exp b
        m[1][0][0] = 0; m[1][0][1] = l%MOD;
        m[1][1][0] = 1; m[1][1][1] = k%MOD;

        // Exp ans
        m[2][0][0] = 1; m[2][0][1] = 0;
        m[2][1][0] = 0; m[2][1][1] = 1;

        while (n) {
            if (n&1) mult(2, 1);
            mult(1, 1);
            n >>= 1;
        }
        mult(0, 2);
        printf("%.6lld\n", m[0][0][0]);
    }
    return 0;
}

/*

n    a(n)     b(n)
0    1        k
1    k        l+k2
...
i    b(n-1)   l*a(n-1)+k*b(n-1)

*/
