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
const int N = 1e4+5;

ll a, b;

ll chk (ll i) {
    if (i == 1) return 1;
    if (i&1) return 1+chk(3*i+1);
    return 1+chk(i>>1);
}

int main () {
    while (~scanf("%lld%lld", &a, &b)) {
        ll maxi = 0;
        for (ll i = min(a, b); i <= max(a, b); i++)
            maxi = max(maxi, chk(i));
        printf("%lld %lld %lld\n", a, b, maxi);
    }
    return 0;
}
