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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e2;

int n, t;
ll v[N];

int main () {
    while (~scanf("%d%d", &n, &t)) {
        for (int i = 0; i < n; i++) scanf("%lld", &v[i]);
        map <ll, ll> x, y;
        for (int m = 1; m < (1 << n/2); m++) {
            ll sum = 0;
            for (int i = 0; i < n/2; i++)
                if (m&(1<<i)) sum += v[i];
            x[sum]++;
        }
        for (int m = 1; m < (1 << n-n/2); m++) {
            ll sum = 0;
            for (int i = 0; i < n-n/2; i++)
                if (m&(1<<i)) sum += v[n/2+i];
            y[sum]++;
        }
        ll ans = x[t] + y[t];
        for (auto k : x) if (k.st != t) ans += (k.nd)*y[t-k.st];
        printf("%lld\n", ans);
    }
    return 0;
}
