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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 5e2+10;

int n, m, e[N][N], ok = 1, zeroline;

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &e[i][j]);
    for (int i = 1; i <= n; i++) {
        int hasnonzeros = 0;
        for (int j = 1; j <= m; j++) if (e[i][j] != 0) {
            if (zeroline) ok = 0;
            hasnonzeros = 1;
            for (int a = i+1; a <= n; a++) for (int b = 1; b <= j; b++)
                if (e[a][b] != 0) ok = 0;
            break;
        }
        if (!hasnonzeros) zeroline = 1;
    }
    printf("%s\n", ok ? "S" : "N");
    return 0;
}
