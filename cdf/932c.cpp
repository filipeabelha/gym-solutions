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

int n, a, b, u, v;

int chk (int n, int a, int b) {
    if (n >= a)     u++, n -= a;
    if (n >= b)     v++, n -= b;
    if (n == 0)     return 1;
    if (n < a and n < b and n > 0) return 0;
    if (n % a == 0) {
        u += n/a;
        return 1;
    }
    if (n % b == 0) {
        v += n/b;
        return 1;
    }
    return chk(n, a, b);
}

bool ok = false;

int main () {
    scanf("%d%d%d", &n, &a, &b);
    if      (n % a == 0)   u = n/a, ok = true;
    else if (n % b == 0)   v = n/b, ok = true;
    else if (chk(n, a, b)) ok = true;
    if (!ok) printf("-1\n");
    else {
        for (int i = 1; i <= u; i++) {
            printf("%d ", i*a);
            for (int j = 1; j <= a-1; j++) {
                printf("%d ", j+(i-1)*a);
            }
        }
        for (int i = 1; i <= v; i++) {
            printf("%d ", u*a+i*b);
            for (int j = 1; j <= b-1; j++) {
                printf("%d ", u*a+j+(i-1)*b);
            }
        }
        printf("\n");
    }
    return 0;
}
