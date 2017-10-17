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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e6+5;

int n, k, d[N], val, ans;
char ss[N];
queue <int> q;

int main () {
    scanf("%d %d ", &n, &k);
    cl(d, 63);
    for (int i = 0; i < n; i++) {
        scanf(" %s", ss);
        int sz = strlen(ss);
        reverse(ss, ss+sz);
        int v = 0;
        for (int j = 0; j < sz; j++) {
            v += (ss[j] == '1')*(1 << j);
        }
        d[v] = 0;
        q.push(v);
    }
    while (q.size()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < k; i++) {
            int u = x;
            if (x & (1<<i)) u -= (1<<i);
            else u += (1<<i);
            if (d[u] > d[x]+1) {
                d[u] = d[x]+1;
                val = max(val, d[u]);
                if (val == d[u]) ans = u;
                q.push(u);
            }
        }
    }
    for (int i = k-1; i >= 0; i--) printf("%c", ans&(1<<i) ? '1' : '0');
    printf("\n");
    return 0;
}
