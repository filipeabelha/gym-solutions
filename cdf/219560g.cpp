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
const int N = 1e5+5;

int A, B, C, D, n, a, b, c, d, p;
int price = INF;

int main () {
    freopen("giant.in", "r", stdin);
    freopen("giant.out", "w", stdout);
    scanf("%d%d%d%d%d", &A, &B, &C, &D, &n);
    while (n--) {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &p);

        int aa, bb, cc, dd, x, y;
        aa = bb = cc = dd = x = y = 0;
        while (aa < A or cc < C) {
            aa += a;
            cc += c;
            x++;
        }
        while (bb < B or dd < D) {
            bb += b;
            dd += d;
            y++;
        }
        price = min(price, x*y*p);

        swap(A, B);
        swap(C, D);

        aa = bb = cc = dd = x = y = 0;
        while (aa < A or cc < C) {
            aa += a;
            cc += c;
            x++;
        }
        while (bb < B or dd < D) {
            bb += b;
            dd += d;
            y++;
        }
        price = min(price, x*y*p);
    }
    printf("%d\n", price);
    return 0;
}
