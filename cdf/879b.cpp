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
const int N = 1e5+5;

int n, p[N], ok, maxi;
ll k;

int main () {
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        maxi = max(maxi, p[i]);
    }
    for (int i = 1; i <= n-k; i++) {
        int cont = 0;
        for (int j = 1; j <= k-(i>1); j++) if (p[i+j] > p[i]) {
            i = i+j-1;
            cont = 1;
            break;
        }
        if (cont) continue;

        printf("%d\n", p[i]);
        ok = 1;
        break;
    }
    if (!ok) printf("%d\n", maxi);
    return 0;
}