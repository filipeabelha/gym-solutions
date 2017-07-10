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

int x, y, n;

int main () {
    while (~scanf("%d%d%d", &x, &y, &n) and x and y and n) {
        vii t;
        vi h;
        int nxt = 0;
        for (int i = 0; i < y; i++) h.pb(-1);
        for (int i = 0; i < x; i++) {
            vi lin;
            for (int z, j = 0; j < y; j++) {
                scanf("%d", &z);
                lin.pb(z);
                if (!z) h[j] = i, nxt = j;
            }
            t.pb(lin);
        }
        for (int z, i = 0; i < n; i++) {
            scanf("%d", &z);
            if (!nxt and h[nxt] < 0) continue;
            t[h[nxt]][nxt] = z;
            h[nxt]--;
            while (h[nxt] < 0 and nxt) nxt--;
        }
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                printf("%d%s", t[i][j], j < y-1 ? " " : "\n");
    }
    return 0;
}
