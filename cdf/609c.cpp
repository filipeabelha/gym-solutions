#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll n, sum;

int main () {
    scanf("%lld", &n);
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    sort(a.begin(), a.end());
    ll x = sum/n;
    ll r = sum%n;
    ll sum = 0;
    for (int i = n-1; i >= 0; i--) {
        int targ = x;
        if (r > 0) targ++, r--;
        sum += abs(a[i]-targ);
    }
    printf("%lld\n", sum/2);

    return 0;
}
