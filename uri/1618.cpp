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

int n, ok;
int ax, ay;
int bx, by;
int cx, cy;
int dx, dy;
int rx, ry;

int main () {
    scanf("%d", &n); while (n--) {
        ok = 1;
        scanf("%d%d", &ax, &ay);
        scanf("%d%d", &bx, &by);
        scanf("%d%d", &cx, &cy);
        scanf("%d%d", &dx, &dy);
        scanf("%d%d", &rx, &ry);
        if (rx > cx or rx > bx) ok = 0;
        if (rx < dx or rx < ax) ok = 0;
        if (ry > dy or ry > cy) ok = 0;
        if (ry < ay or ry < by) ok = 0;
        printf("%d\n", ok ? 1 : 0);
    }
    return 0;
}
