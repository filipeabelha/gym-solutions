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

ll n, k, a[N];

ll typ, amnt, mini = INF;

int main () {
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= k; i++) scanf("%lld", &a[i]);

    typ = 1;
    amnt = n / a[1];
    mini = n % a[1];

    for (int i = 2; i <= k; i++) {
        if (mini > n % a[i]) {
            mini = n % a[i];
            amnt = n / a[i];
            typ = i;
        }
    }

    printf("%lld %lld\n", typ, amnt);
    return 0;
}
