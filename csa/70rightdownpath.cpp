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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e2+5;

int n, m, t[N][N], ans;

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &t[i][j]);
    for (int i = 1; i <= n-1; i++)
        for (int j = 2; j <= m; j++) {
            if (t[i][j] and t[i+1][j] and t[i][j-1]) {
                int a = j-1;
                int b = i+1;
                while (b+1 <= n and t[b+1][j]) b++;
                while (a-1 >= 1 and t[i][a-1]) a--;
                ans = max(ans, j-a+1+b-i);
            }
        }
    printf("%d\n", ans);
    return 0;
}
