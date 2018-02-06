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
const int N = 3e5+5;

int n, m, a, b, ans, cnt;
int inc[N], dp[N][30];
char s[N];
set <int> adj[N];
queue <int> q;

int main () {
    scanf("%d%d", &n, &m);
    scanf(" %s", s);
    for (int i = 1; i <= m; i++) {
        scanf(" %d %d", &a, &b);
        if (!adj[a].count(b)) inc[b]++;
        adj[a].insert(b);
    }

    for (int i = 1; i <= n; i++) if (!inc[i]) cnt++, dp[i][s[i-1]-'a']++, q.push(i);

    while (q.size()) {
        int u = q.front(); q.pop();

        for (auto v : adj[u]) {
            int c = s[v-1]-'a';

            for (int i = 0; i < 26; i++) dp[v][i] = max(dp[v][i], dp[u][i]);
            dp[v][c] = max(dp[v][c], dp[u][c]+1);

            if (inc[v] and !(--inc[v])) cnt++, q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) for (int j = 0; j < 26; j++)
        ans = max(ans, dp[i][j]);

    printf("%d\n", cnt == n ? ans : -1);

    return 0;
}
