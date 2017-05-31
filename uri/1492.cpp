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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

ll x, y, ee[100];

ll cnt (ll n) {
    ll ans = 0;
    for (ll e = 1; e <= 55; e++) {
        ll i = ee[e];
        ans += (i/2)*(n/i);
        if (n%i >= i/2) ans += (n%i)-i/2+1;
    }
    return ans;
}

int main () {
    ee[0] = 1;
    for (int i = 1; i <= 55; i++) ee[i] = 2*ee[i-1];
    while (~scanf("%lld%lld", &x, &y))
        printf("%lld\n", cnt(y)-cnt(x-1));
    return 0;
}
