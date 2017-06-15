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

ll n, b, l, r, m, d, co, li;

int main () {
    scanf("%lld%lld", &n, &b);
    if (n % 2 == 0) l = 0, r = n;
    if (n % 2 == 1) l = 1, r = n;
    while (l < r) {
        m = (l+r)/2;
        m += (m%2==1)*(n%2==0)+(m%2==0)*(n%2==1);
        if (b-(n*n-m*m) > 4*m-4) r = m-2;
        else l = m;
    }
    if (b-(n*n-m*m) > 4*m-4 and n > 1) m -= 2;
    b -= n*n-m*m;
    co = (n-m)/2+(n==1);
    li = (n-m)/2+1;
    if (b > 0) d = (b > m-0 ? m-0 : b), co += d, b -= d;
    if (b > 0) d = (b > m-1 ? m-1 : b), li += d, b -= d;
    if (b > 0) d = (b > m-1 ? m-1 : b), co -= d, b -= d;
    if (b > 0) d = (b > m-1 ? m-1 : b), li -= d, b -= d;
    printf("%lld %lld\n", li, co);
    return 0;
}
