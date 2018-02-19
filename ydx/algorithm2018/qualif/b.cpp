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

int n, z;
int t[N][N], ans[N][N];
map <int, int> f;

void pr() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            printf("%d ", ans[i][j]);
    printf("\n");
}

void go (int c) {
    for (int k = 2; k <= 2*n; k++) {
        bool did = false;
        for (int i = 1; i <= n; i++) {
            bool ok = false;
            bool noooo = false;
            for (int j = 1; j <= n; j++) {
                if (ans[i][j] and c+(i != j) and ans[i][j] == t[k][j]) ok = true;
                if (ans[i][j] and ans[i][j] != t[k][j]) noooo = true;
            }
            if (ok and !noooo) did = true;
            if (ok and !noooo) for (int j = 1; j <= n; j++) ans[i][j] = t[k][j];
        }

        if (did) continue;

        for (int j = 1; j <= n; j++) {
            bool ok = false;
            bool noooo = false;
            for (int i = 1; i <= n; i++) {
                if (ans[i][j] and c+(i != j) and ans[i][j] == t[k][i]) ok = true;
                if (ans[i][j] and ans[i][j] != t[k][i]) noooo = false;
            }
            if (ok and !noooo) for (int i = 1; i <= n; i++) ans[i][j] = t[k][i];
        }

    }
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= 2*n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &t[i][j]);

    for (int j = 1; j <= n; j++) {
        f.clear();
        for (int i = 1; i <= 2*n; i++) {
            f[t[i][j]]++;
            if (f[t[i][j]] == 2) ans[j][j] = t[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        bool ok = true;
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] and ans[i][j] != t[1][j]) ok = false;
        }
        if (ok) for (int j = 1; j <= n; j++) ans[i][j] = t[1][j];
    }

    go(0);
    go(1);

    pr();

    return 0;
}
