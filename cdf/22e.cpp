#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int N = 1e5+5;

int cycleId[N], vis[N], f[N], inc[N];
int n;

vector <int> compon, leaves[N];
vector <pii> ans;

void dfs (int v) {
    vis[v] = 1;
    if (!vis[f[v]]) dfs(f[v]);
    cycleId[v] = cycleId[f[v]];
}

int main () {
    for (int i = 0; i < N; i++) cycleId[i] = i;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
        inc[f[i]]++;
    }

    for (int i = 1; i <= n; i++) dfs(i);

    for (int i = 1; i <= n; i++) if (!inc[i]) {
        leaves[cycleId[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) compon.push_back(cycleId[i]);
    sort(compon.begin(), compon.end());
    compon.erase(unique(compon.begin(), compon.end()), compon.end());

    if (compon.size() == 1) {
        int x = compon.back();
        for (auto c : leaves[x]) ans.push_back({x, c});
    } else {
        for (int i = 1; i < compon.size(); i++) {
            int x = compon[i-1];
            int y = compon[i];
            for (auto c : leaves[y]) ans.push_back({x, c});
            if (leaves[y].empty()) ans.push_back({x, y});
        }
        int x = compon.back();
        int y = compon[0];
        for (auto c : leaves[y]) ans.push_back({x, c});
        if (leaves[y].empty()) ans.push_back({x, y});
    }

    printf("%d\n", ans.size());
    for (auto p : ans) printf("%d %d\n", p.first, p.second);

    return 0;
}
