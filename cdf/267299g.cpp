#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e3+5;
 
typedef vector <int> vi;
 
vi adj[N];
int n, k, x, dp[N], vis1[N], vis2[N], f[N], id[N], cycleSize[N], cur[N];
 
void dfs1 (int v) {
    if (cur[f[v]]) {
        cycleSize[f[v]] = id[v]-id[f[v]]+1;
    } else if (!vis1[f[v]]) {
        cur[f[v]] = vis1[f[v]] = 1;
        id[f[v]] = id[v]+1;
        dfs1(f[v]);
    }
    cur[v] = 0;
    cycleSize[v] = cycleSize[f[v]];
}
 
int dfs2 (int v) {
    if (vis2[v]) return 0;
    vis2[v] = 1;
 
    int ans = 1;
    for (auto u : adj[v]) ans += dfs2(u);
 
    return ans;
}
 
int main () {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
        adj[i].push_back(f[i]);
        adj[f[i]].push_back(i);
    }
 
 
    for (int i = 1; i <= n; i++) if (!vis1[i]) {
        cur[i] = vis1[i] = 1;
        id[i] = 1;
        dfs1(i);
    }
 
    dp[0] = 1;
    for (int i = 1; i <= n; i++) if (!vis2[i]) {
        int l = cycleSize[i];
        int r = dfs2(i);
        for (int j = N-1; j >= 0; j--) {
            for (int z = l; z <= r; z++) {
                if (j-z >= 0) dp[j] |= dp[j-z];
            }
        }
    }
 
    for (int i = k; i >= 0; i--) if (dp[i]) {
        printf("%d\n", i);
        return 0;
    }
 
    return 0;
}
