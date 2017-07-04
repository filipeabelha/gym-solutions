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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 4e2+10;

int m[N][N], v[8][N][N], n;

int main () {
    while (~scanf("%d", &n) and n) {
        int x, ans = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
            scanf("%d", &m[i][j]);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            v[0][i][j] = x;
            v[1][j][i] = x;
            v[2][i][n-j-1] = x;
            v[3][n-j-1][i] = x;
            v[4][n-i-1][j] = x;
            v[5][j][n-i-1] = x;
            v[6][n-i-1][n-j-1] = x;
            v[7][n-j-1][n-i-1] = x;
        }
        for (int k = 0; k < 8; k++) {
            int ok = 0;
            for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
                if (abs(v[k][i][j]-m[i][j]) <= 100) ok++;
            }
            ans = max(ans, ok);
        }
        printf("%.2Lf\n", (long double) ans*100/(n*n));
    }
    return 0;
}
