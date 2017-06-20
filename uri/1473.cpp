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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 5e2, M = 1e5;

int m[N][N], lin[M], col[M], l, c, li, co, newli, newco, ans;

int main () {
    while (~scanf("%d%d", &l, &c)) {
        for (int i = 1; i <= l; i++) for (int j = 1; j <= c; j++) {
            scanf("%d", &m[i][j]);
            lin[m[i][j]] = i;
            col[m[i][j]] = j;
        }
        for (int n = 1; n <= l*c; n++) {
            li = lin[n];
            co = col[n];
            newli = ((n-1)/c)+1;
            newco = ((n-1)%c)+1;
            if (co != newco) {
                ans++;
                for (int i = 1; i <= l; i++) {
                    swap(col[m[i][newco]], col[m[i][co]]);
                    swap(m[i][newco], m[i][co]);
                }
            }
            if (li != newli) {
                ans++;
                for (int j = 1; j <= c; j++) {
                    swap(lin[m[newli][j]], lin[m[li][j]]);
                    swap(m[newli][j], m[li][j]);
                }
            }
        }
        for (int i = 1; i <= l; i++) for (int j = 1; j <= c; j++)
            if (m[i][j] != c*(i-1)+j) ans = -1;
        ans < 0 ? printf("*\n") : printf("%d\n", ans); ans = 0;
    }
    return 0;
}
