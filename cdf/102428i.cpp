#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector <int> vi;
typedef long long ll;

const int N = 1e5+5;
const int MOD = 1e9+7;

int n, l, k, x, vis[N];
ll memo[N];
vi adj[N], adjr[N];

ll dp (int v) {
    if (v == 1) return memo[v] = 1;
    if (memo[v] != -1) return memo[v];
    ll ans = 0;
    for (auto u : adjr[v]) {
        ans += dp(u);
        ans %= MOD;
    }
    return memo[v] = ans;
}

void dfs (int v) {
    if (vis[v]) return;
    vis[v] = 1;

    for (auto u : adj[v]) dfs(u);
}

int main () {
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= l; i++) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &x);
            adj[i].pb(x);
            adjr[x].pb(i);
        }
    }

    for (int i = 0; i < N; i++) memo[i] = -1;

    ll ans1 = 0;
    ll ans2 = 0;
    dfs(1);
    for (int i = l+1; i <= n; i++) {
        ans1 += dp(i);
        ans1 %= MOD;
        ans2 += vis[i];
    }

    printf("%lld %lld\n", ans1, ans2);

}

