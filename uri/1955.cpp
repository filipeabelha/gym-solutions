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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e3+10;

int n, adj[N][N], vis[N], c[N], ok = 1, frst;

void go (int i) {
    if (!ok) return;
    for (int j = 1; j <= n; j++) {
        if (i != j and !adj[i][j]) {
            if (!c[j]) {
                if (!frst) c[i] = 1, frst = 1;
                c[j] = -c[i];
                go(j);
            } else if (c[i] == c[j]) ok = 0;
        }
    }
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        scanf("%d", &adj[i][j]);
    for (int i = 1; i <= n; i++) go(i);
    printf("%s!\n", ok ? "Bazinga" : "Fail");
    return 0;
}
