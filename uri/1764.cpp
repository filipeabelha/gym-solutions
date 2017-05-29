#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;

#define cl(x, v) memset((x), (v), sizeof(x))
#define st first
#define nd second
#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;

int par[N], sz[N], ver, edg, x, y, z;

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}

int main () {
    while (1) {
        scanf("%d%d", &ver, &edg);
        if (!ver and !edg) break;
        cl(sz, 0); for (int i = 0; i < N; i++) par[i] = i;
        vector<piii> edges;
        for (int i = 0; i < edg; i++) {
            scanf("%d%d%d", &x, &y, &z);
            edges.pb(mp(z, mp(x, y)));
        }
        sort(edges.begin(), edges.end());
        int cost = 0;
        for (auto e : edges)
            if (find(e.nd.st) != find(e.nd.nd))
                unite(e.nd.st, e.nd.nd), cost += e.st;
        printf("%d\n", cost);

    }

    return 0;
}
