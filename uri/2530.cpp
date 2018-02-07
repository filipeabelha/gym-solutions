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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e7+10;

int n, m, u[N], v[N];

int isSub (int i, int j) {
    if (!j) return 1;
    if (!i) return 0;
    if (u[i-1] == v[j-1]) return isSub(i-1, j-1);
    return isSub(i-1, j);
}

int main () {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; i++) scanf("%d", &u[i]);
        for (int i = 0; i < m; i++) scanf("%d", &v[i]);
        printf("%s\n", isSub(n, m) ? "sim" : "nao");
    }
    return 0;
}
