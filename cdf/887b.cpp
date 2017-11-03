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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, c[15][15], v[N];

int main () {
    memset(c, 63, sizeof(c));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    for (int j = 0; j < 6; j++) for (int k = 0; k < 6; k++) for (int l = 0; l < 6; l++) {
        ll x;
        x = c[0][j]; if (x >= 0 and x < 2000) v[x] = 1;
        x = c[1][k]; if (x >= 0 and x < 2000) v[x] = 1;
        x = c[2][l]; if (x >= 0 and x < 2000) v[x] = 1;
        x = 10*c[0][k] + c[1][l]; if (x >= 0 and x < 2000) v[x] = 1;
        x = 10*c[0][k] + c[2][l]; if (x >= 0 and x < 2000) v[x] = 1;
        x = 10*c[1][k] + c[2][l]; if (x >= 0 and x < 2000) v[x] = 1;
        x = 10*c[2][k] + c[1][l]; if (x >= 0 and x < 2000) v[x] = 1;
        x = 10*c[2][k] + c[0][l]; if (x >= 0 and x < 2000) v[x] = 1;
        x = 10*c[1][k] + c[0][l]; if (x >= 0 and x < 2000) v[x] = 1;
        x = 100*c[0][j] + 10*c[1][k] + c[2][l]; if (x >= 0 and x < 2000) v[x] = 1;
        x = 100*c[0][j] + 10*c[2][k] + c[1][l]; if (x >= 0 and x < 2000) v[x] = 1;
        x = 100*c[1][j] + 10*c[0][k] + c[2][l]; if (x >= 0 and x < 2000) v[x] = 1;
        x = 100*c[1][j] + 10*c[2][k] + c[0][l]; if (x >= 0 and x < 2000) v[x] = 1;
        x = 100*c[2][j] + 10*c[0][k] + c[1][l]; if (x >= 0 and x < 2000) v[x] = 1;
        x = 100*c[2][j] + 10*c[1][k] + c[0][l]; if (x >= 0 and x < 2000) v[x] = 1;
    }
    for (int i = 1; i < 2000; i++) {
        if (!v[i]) return 0*printf("%d\n", i-1);
    }
    return 0;
}
