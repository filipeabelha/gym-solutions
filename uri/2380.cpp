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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e5+10;

int n, k, x, y, par[N];
char op, chr;

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    par[b] = a;
}

int main () {
    for (int i = 0; i < N; i++) par[i] = i;
    scanf("%d %d%c", &n, &k, &chr);
    for (int i = 0; i < k; i++) {
        scanf("%c %d %d%c", &op, &x, &y, &chr);
        if (op == 'F') unite(x, y);
        else printf("%s\n", find(x) == find(y) ? "S" : "N");
    }
    return 0;
}
