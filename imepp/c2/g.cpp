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
const int N = 1e3+5;

ll n, a[N], b[N], A[N][N], B[N][N], ans;

int main () {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    for (int i = 1; i <= n; i++) {
        A[i][i] = a[i];
        B[i][i] = b[i];
        for (int j = i+1; j <= n; j++) A[i][j] = A[i][j-1]|a[j];
        for (int j = i+1; j <= n; j++) B[i][j] = B[i][j-1]|b[j];
    }
    for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) {
        ans = max(ans, A[i][j]+B[i][j]);
    }
    printf("%lld\n", ans);
    return 0;
}
