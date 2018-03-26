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
#define gcd(x, y) __gcd((x), (y))

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
const int N = 1e6;

int main () {
    for (ll i = 1; i <= 2000; i++)
        for (ll j = i; i+j <= 2000; j++)
            for (ll k = j; i+j+k <= 2000; k++) {
                if (i*j*k == N) continue;
                ll l = N*(i+j+k)/(i*j*k-N);
                if (l >= k and i+j+k+l <= 2000 and N*(i+j+k+l) == i*j*k*l)
                    printf("%lld.%02lld %lld.%02lld %lld.%02lld %lld.%02lld\n",
                           i/100, i%100,
                           j/100, j%100,
                           k/100, k%100,
                           l/100, l%100);
            }
    return 0;
}
