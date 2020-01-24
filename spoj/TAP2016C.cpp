#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector <int> vi;

const int N = 5e4+5;

int n, m, a, b;
int t[N], memo[N], v[N];
vi adj[N];

int dp (int v) {
    if (~memo[v]) return memo[v];

    int ans = t[v];
    for (auto u : adj[v]) ans = max(ans, dp(u));

    return memo[v] = ans;

}

int main () {
    while (~scanf("%d%d", &n, &m)) {
        memset(t, 0, sizeof t);
        memset(v, 0, sizeof v);
        memset(memo, -1, sizeof memo);
        for (int i = 0; i < N; i++) adj[i].clear();

        while (m--) {
            scanf("%d%d", &a, &b);
            adj[b].pb(a);
        }
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            t[x] = i;
        }

        for (int i = 1; i <= n; i++) dp(i);

        for (int i = 1; i <= n; i++) v[dp(i)]++;

        for (int i = 1; i < N; i++) v[i] += v[i-1];

        for (int i = 1; i <= n; i++) printf("%d\n", v[i]);

    }
    return 0;
}
