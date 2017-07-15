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

int tc, n, cnt, vis[N], d[5];

int krap (int x, int dep) {
    if (vis[x]) return -1;
    vis[x] = 1;
    if (x == 6174) return dep;
    for (int i = 0; i < 4; i++) d[i] = x%10, x/=10;
    sort(d, d+4);
    int mai = d[3]*1000 + d[2]*100 + d[1]*10 + d[0];
    int men = d[0]*1000 + d[1]*100 + d[2]*10 + d[3];
    return krap (mai-men, dep+1);
}

int main () {
    scanf("%d", &tc);
    while (tc-- and ++cnt) {
        scanf("%d", &n);
        cl(vis, 0);
        printf("Caso #%d: %d\n", cnt, krap(n, 0));
    }
    return 0;
}
