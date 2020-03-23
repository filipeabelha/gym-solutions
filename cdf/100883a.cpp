#include <bits/stdc++.h>
using namespace std;
 
mt19937_64 llrand(random_device{}());
 
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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
 
const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 21;
const int M = 11e5;

double p[N][N], memo[M];
int n;

double dp (int x) {
    if (abs(memo[x]+1) > EPS) return memo[x];

    memo[x] = 0;

    vi bits_on;
    for (int k = 0; k < n; k++) if (x & (1 << k)) bits_on.pb(k);

    int cnt = __builtin_popcount(x);

    for (int k = 0; k < n; k++) {
        if (!(x & (1 << k))) {
            double avg = 0;
            for (auto i : bits_on) avg += p[i][k];
            avg /= cnt;
            memo[x] += avg*dp(x|(1 << k))*2/(cnt+1);
        }
    }
    return memo[x];

}

void clr () {
    for (int i = 0; i < M; i++) {
        memo[i] = -1;
    }
}

int main () {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        printf("Case %d: ", tc);
        cl(p, 0);

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lf", &p[i][j]);
            }
        }

        clr();
        memo[(1 << n)-1] = 1.0;

        for (int i = 0; i < n; i++) {
            printf("%.6lf%c", dp(1 << i), " \n"[i+1==n]);
        }
    }

    return 0;
}
