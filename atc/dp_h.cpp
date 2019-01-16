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
const int N = 1e3+5;

int a, b;
char c;
ll dp[N][N];

int main () {
    scanf("%d%d", &a, &b);
    dp[1][1] = 1;
    for (int i = 1; i <= a; i++) for (int j = 1; j <= b; j++) {
        scanf(" %c", &c);
        if (i == 1 and j == 1) continue;
        if (c == '.') dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
    }
    printf("%lld\n", dp[a][b]);
    return 0;
}
