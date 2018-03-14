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
const int N = 5e2+5;

int n, m, t[N][N], a[N][N];

pii ans[N][N];

int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, -1, +1};

void go (int i, int j) {
    if (ans[i][j] != mp(0,0)) {
        pii p = ans[i][j];
        a[p.st][p.nd]++;
        return;
    }
    int ok = 1;
    int mini = INF;
    int xmini = INF;
    int ymini = INF;
    for (int k = 0; k < 8; k++) {
        int x = i+dx[k];
        int y = j+dy[k];
        if (x < 1 or x > n) continue;
        if (y < 1 or y > m) continue;
        if (t[x][y] < t[i][j] and t[x][y] < mini) {
            mini = t[x][y];
            xmini = x;
            ymini = y;
            ok = 0;
        }
    }
    if (ok) {
        ans[i][j] = mp(i, j);
        a[i][j]++;
    }
    else {
        go(xmini, ymini);
        ans[i][j] = ans[xmini][ymini];
    }
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &t[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            go(i, j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d%c", a[i][j], " \n"[j==m]);
        }
    }
    return 0;
}
