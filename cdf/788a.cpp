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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e5+10;

ll n, p = 1, u[N], a[N], b[N], maxnow, maxglo;

int main () {
    scanf("%lld", &n);

    for (int i = 0; i < n; i++) scanf("%lld", &u[i]);

    for (int i = 0; i < n-1; i++) a[i] = abs(u[i]-u[i+1])*p, p *= -1;

    p = -1;

    for (int i = 0; i < n-1; i++) b[i] = abs(u[i]-u[i+1])*p, p *= -1;

    maxnow = maxglo = a[0];

    for (int i = 1; i < n; i++)
        maxnow = max(maxnow+a[i], a[i]), maxglo = max(maxglo, maxnow);

    maxnow = b[0];

    for (int i = 1; i < n; i++)
        maxnow = max(maxnow+b[i], b[i]), maxglo = max(maxglo, maxnow);

    printf("%lld\n", maxglo);

    return 0;
}
