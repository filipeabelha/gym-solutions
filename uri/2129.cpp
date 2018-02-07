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
const int INF = 0x3f3f3f3f;
const ll MOD = 100000000000ll;
const int N = 1e6+5;

ll n, ans[N], cnt;

ll solve (ll n) {
    if (ans[n] >= 0) return ans[n];
    if (n == 0) return ans[0] = 1;
    if (n == 1) return ans[1] = 1;
    if (n == 2) return ans[2] = 2;
    if (n == 3) return ans[3] = 6;
    if (n == 4) return ans[4] = 4;
    if (n == 5) return ans[5] = 2;
    if (n == 6) return ans[6] = 2;
    if (n == 7) return ans[7] = 4;
    if (n == 8) return ans[8] = 2;
    if (n == 9) return ans[9] = 8;
    ll x = n; x /= 10; x %= 10;
    if (x&1) return ans[n] = (4*solve(n/5)*solve(n%10))%10;
    return ans[n] = (6*solve(n/5)*solve(n%10))%10;
}

int main () {
    cl(ans, -1);
    while (~scanf("%lld", &n) and ++cnt)
        printf("Instancia %lld\n%lld\n\n", cnt, solve(n));
    return 0;
}
