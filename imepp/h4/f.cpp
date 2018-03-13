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

ll a, b, n;

int main () {
    scanf("%lld", &n);
    if (n > 2 and n % 2 == 0) {
        a = n/2;
        b = 1;
        return printf("%lld %lld\n", a*a-b*b, a*a+b*b), 0;
    } else if (n % 2 == 1) {
        a = n/2+1;
        b = n/2;
        if (a and b) return printf("%lld %lld\n", 2*a*b, a*a+b*b), 0;
    }
    printf("-1\n");
    return 0;
}
