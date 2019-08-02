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
const int N = 2e5+5;

int q, n, x, y, f1, f2, f3, f4, xa, xb, ya, yb;

int main () {
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        xa = ya = -1e5;
        xb = yb = 1e5;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d%d%d", &x, &y, &f1, &f2, &f3, &f4);

            int xu, xv, yu, yv;

            x += 1e5;
            y += 1e5;

            if (f1 and f3) xu = 0, xv = 2e5;
            else if (f1)   xu = 0, xv = x;
            else if (f3)   xu = x, xv = 2e5;
            else           xu = x,   xv = x;

            if (f2 and f4) yu = 0, yv = 2e5;
            else if (f4)   yu = 0, yv = y;
            else if (f2)   yu = y, yv = 2e5;
            else           yu = y, yv = y;

            xu -= 1e5;
            xv -= 1e5;

            yu -= 1e5;
            yv -= 1e5;

            xa = max(xa, xu);
            xb = min(xb, xv);
            ya = max(ya, yu);
            yb = min(yb, yv);
        }
        if (xa <= xb and ya <= yb) printf("1 %d %d\n", xa, ya);
        else printf("0\n");
    }
    return 0;
}
