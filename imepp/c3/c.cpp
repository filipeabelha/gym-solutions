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

int t[10][10], atk[10][10][10];
int tc, found, cnt;

void mark (int i, int j, int k, int w) {
    int a, b, c, d;

    if      (i <= 3) a = 1, b = 3;
    else if (i <= 6) a = 4, b = 6;
    else if (i <= 9) a = 7, b = 9;

    if      (j <= 3) c = 1, d = 3;
    else if (j <= 6) c = 4, d = 6;
    else if (j <= 9) c = 7, d = 9;

    for (int u = 1; u <= 9; u++) atk[u][j][k] += w;
    for (int v = 1; v <= 9; v++) atk[i][v][k] += w;

    for (int u = a; u <= b; u++) for (int v = c; v <= d; v++)
        atk[u][v][k] += w;
}

void bk (int i, int j, int k) {

    t[i][j] = k;
    mark(i, j, k, 1);
    cnt--;
    if (!cnt) {
        for (int u = 1; u <= 9; u++) for (int v = 1; v <= 9; v++)
            printf("%d%c", t[u][v], " \n"[v==9]), found = 1;
        return;
    }

    for (int u = 1; u <= 9; u++) for (int v = 1; v <= 9; v++)
        if (!t[u][v]) {
            for (int w = 1; w <= 9; w++) {
                if (!atk[u][v][w]) bk(u, v, w);
                if (found) return;
            }
            t[i][j] = 0;
            mark(i, j, k, -1);
            cnt++;
            return;
        }
}

int main () {
    scanf("%d", &tc);
    while (tc--) {
        cl(atk, 0);
        found = 0;
        cnt = 0;

        for (int i = 1; i <= 9; i++) for (int j = 1; j <= 9; j++) {
            scanf("%d", &t[i][j]);
            mark(i, j, t[i][j], 1);
            if (!t[i][j]) cnt++;
        }

        for (int i = 1; i <= 9; i++) for (int j = 1; j <= 9; j++)
            if (!t[i][j]) {
                for (int k = 1; k <= 9; k++)
                    if (!atk[i][j][k]) bk(i, j, k);
                if (!found) {
                    printf("No solution\n");
                    goto end;
                }
            }
        end:
        if (1);

    }
    return 0;
}
