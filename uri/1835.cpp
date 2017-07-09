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
const int N = 1e2+5;

int tc, n, m, ans, cnt;
int par[N];

int find (int k) {
    return (par[k] == k ? k : par[k] = find(par[k]));
}

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    par[b] = a;
    ans++;
}

int main () {
    scanf("%d", &tc);
    while (tc-- and ++cnt) {
        for (int i = 0; i < N; i++) par[i] = i;
        ans = 0;

        scanf("%d%d", &n, &m);
        for (int a, b, i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            unite(a, b);
        }

        ans = n-1-ans;

        printf("Caso #%d: ", cnt);
        (!ans ? printf("a promessa foi cumprida\n") : printf("ainda falta(m) %d estrada(s)\n", ans));

    }
    return 0;
}
