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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e3+10;

int n, m, l, t[N][N];

int main () {
    while (~scanf("%d%d%d", &m, &n, &l) and n and m and l) {
        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
            scanf("%d", &t[i][j]);
        for (int j = 0; j < m; j++) {
            int sz = 0;
            for (int i = 0; i < n; i++) {
                if (t[i][j]) sz++;
                if (!t[i][j] or i == n-1) {
                    if (sz >= l) ans++;
                    sz = 0;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
