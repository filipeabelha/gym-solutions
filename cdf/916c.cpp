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
const int INF = 99999989, MOD = 1e9+7;
const int N = 1e5+5;

ll n, m;

int main () {
    scanf("%lld%lld", &n, &m);
    if (n == 2) {
        printf("2 2\n");
        printf("1 2 2\n");
    } else {
        printf("2 %d\n", INF);
        printf("1 %lld 2\n", n); m--;
        for (int i = 2; i <= n-2; i++) m--, printf("%d %d 1\n", i-1, i);
        printf("%lld %lld %lld\n", n-2, n-1, INF-n+1); m--;
        for (int i = 1; i <= n; i++) for (int j = i+1; j <= n; j++) {
            if (m <= 0) break;
            if (i == 1 and j == n) continue;
            if (j == i+1) continue;
            printf("%d %d %d\n", i, j, INF); m--;
        }
        if (m > 0) printf("%lld %lld %d\n", n-1, n, INF);
    }
    return 0;
}
