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
const int N = 1e5+5;

ll n, q, p;

int main () {
    scanf("%lld%lld", &n, &q);
    n = 2*n-1;
    while (q--) {
        scanf("%lld", &p);
        if (p&1) {
            printf("%lld\n", (p+1)/2);
            continue;
        }
        while ((n+1+p)/2 < n) {
            p = (n+1+p)/2;
            if (p&1) break;
        }
        printf("%lld\n", (p == n-1) ? (n+1)/2 : (p+1)/2);
    }
    return 0;
}
