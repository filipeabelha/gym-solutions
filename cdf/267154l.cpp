#include <bits/stdc++.h>
using namespace std;
 
#define gcd(x, y) __gcd((x), (y))
#define pb push_back
 
#define st first
#define nd second
 
typedef long long ll;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
 
ll a, b, n, x, y, h, ans;
 
map <pll, vector <pll> > m;
 
int main () {
    scanf("%lld%lld%lld", &a, &b, &n);
    while (n--) {
        scanf("%lld%lld%lld", &x, &y, &h);
        x -= a;
        y -= b;
        ll g = gcd(abs(x), abs(y));
        x /= g;
        y /= g;
        m[{x, y}].pb({g, h});
    }
    for (auto& p : m) {
        vector <pll> &v = p.nd;
        sort(v.begin(), v.end());
 
        vector <ll> lis;
 
        for (auto& q : v) {
            ll x = q.nd;
            if (lis.empty() or x > lis.back()) lis.pb(x);
            else {
                int pos = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
                lis[pos] = x;
            }
        }
 
        ans += lis.size();
    }
 
    printf("%lld\n", ans);
 
    return 0;
}
