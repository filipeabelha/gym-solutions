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
const int N = 1e3+5;

int w, h, n, t[N][N];
int xa, xb, ya, yb;

int main () {
    while (~scanf("%d%d%d", &w, &h, &n) and (w or h or n)) {
        cl(t, 0);
        while (n--) {
            scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
            for (int i = min(xa, xb); i <= max(xa, xb); i++)
                for (int j = min(ya, yb); j <= max(ya, yb); j++)
                    t[i][j] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= w; i++)
            for (int j = 1; j <= h; j++)
                if (!t[i][j]) ans++;
        if (ans == 0) printf("There is no empty spots.\n");
        if (ans == 1) printf("There is one empty spot.\n");
        if (ans > 1) printf("There are %d empty spots.\n", ans);
    }
    return 0;
}
