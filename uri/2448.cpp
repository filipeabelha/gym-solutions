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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 5e4+10;

map <int, int> k;
int n, m, x, v[N], ans;

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &x), k[x] = i;
    for (int i = 1; i <= m; i++) scanf("%d", &v[i]);
    ans = k[v[1]]-1;
    for (int i = 1; i <= m-1; i++) ans += abs(k[v[i]]-k[v[i+1]]);
    printf("%d\n", ans);
    return 0;
}
