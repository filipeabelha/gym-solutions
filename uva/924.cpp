#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define cl(x,v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

const int N = 2510;
vii adj(N);
queue <pii> q;
int vis[N], dep[N], n, tc, maxboom, maxday;

void bfs (int x, int depth) {
    vis[x] = 1;
    for (int i = 0; i < adj[x].size(); i++) {
        int el = adj[x][i];
        if (!vis[el]) {
           q.push(mp(el, depth+1));
           dep[depth+1]++;
           if (dep[depth+1] > maxboom) {
               maxboom = dep[depth+1];
               maxday = depth+1;
           }
           vis[el] = 1;
        }
    }
    while (!q.empty()) {
        int qf = q.front().first;
        int qs = q.front().second;
        q.pop();
        bfs(qf, qs);
    }
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k, z;
        scanf("%d", &k);
        while (k--) scanf("%d", &z), adj[i].pb(z);
    }
    scanf("%d", &tc);
    while (tc--) {
        maxboom = 0; maxday = 0;
        cl(dep, 0); cl(vis, 0);
        int t; scanf("%d", &t);
        bfs(t,0);
        if (!maxboom) printf("0\n");
        else printf("%d %d\n", maxboom, maxday);
    }
    return 0;
}
