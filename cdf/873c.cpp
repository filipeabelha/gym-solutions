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
const int N = 1e3+5;

int t[N][N];
int sc, re;
int n, m, k;
int subone, maxone, maxsum, subsum;

int main () {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        scanf("%d", &t[i][j]);
    for (int c = 1; c <= m; c++) {
        subone = maxone = maxsum = 0;
        for (int i = 1; i <= n; i++) if (t[i][c]) {
            subone++;
            subsum = 0;
            for (int j = 0; j < k; j++) if (i+j <= n) subsum += t[i+j][c];
            if (maxsum < subsum) {
                maxsum = subsum;
                maxone = subone;
            }
        }
        if (maxsum > 0) {
            sc += maxsum;
            re += maxone-1;
        }
    }
    printf("%d %d\n", sc, re);
    return 0;
}
