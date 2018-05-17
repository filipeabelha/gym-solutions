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
#define gcd(x, y) __gcd((x), (y))

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
const int N = 1e2+5;

int n, m, ans[N][N];
char t[N][N];
int dx[] = {+1, -1, +0, +0, +1, -1, +1, -1};
int dy[] = {+0, +0, +1, -1, +1, -1, -1, +1};

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &t[i][j]);
            if (t[i][j] == '.') t[i][j] = '0';
            if (t[i][j] == '*') {
                for (int k = 0; k < 8; k++) {
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if (x < 1 or x > n) continue;
                    if (y < 1 or y > m) continue;
                    ans[x][y]++;
                }
            }
        }
    }

    int ok = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (t[i][j] >= '0' and t[i][j] <= '9' and ans[i][j] != t[i][j]-'0') ok = 0;
        }
    }
    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}
