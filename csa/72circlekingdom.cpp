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

ll n, v[N], sum, ans = LINF, ind = -1;

int main () {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &v[i]), sum += v[i];
    for (int i = n; i < 2*n; i++) v[i] = v[i-n];
    for (int i = 0; i < n; i++) {
        ll tot = 0;
        ll mx = 0;
        for (int j = 0; j < n; j++) {
            tot += v[i+j];
            mx = max(mx, min(tot, sum-tot));
        }
        if (ans > mx) {
            ans = mx;
            ind = i+1;
        }
    }
    printf("%lld\n", ind);
    return 0;
}
