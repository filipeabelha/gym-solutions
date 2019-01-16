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
const int N = 3e2+5;

int n, x, a, b, c;
ld memo[N][N][N];

ld dp (int i, int j, int k) {
    if (memo[i][j][k]) return memo[i][j][k];
    if (i+j+k > n) return 0;
    if (i or j or k) memo[i][j][k] = (ld) n/(i+j+k);
    if (i) memo[i][j][k] += i*dp(i-1, j,   k)  /(i+j+k);
    if (j) memo[i][j][k] += j*dp(i+1, j-1, k)  /(i+j+k);
    if (k) memo[i][j][k] += k*dp(i,   j+1, k-1)/(i+j+k);
    return memo[i][j][k];
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == 1) a++;
        if (x == 2) b++;
        if (x == 3) c++;
    }
    printf("%.10Lf\n", dp(a, b, c));
    return 0;
}
