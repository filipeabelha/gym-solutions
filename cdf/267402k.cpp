#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5+5;
 
int k, n, vis[2*N], ord[2*N], ordn, cnt, cmp[2*N], val[N];
vector <int> adj[2*N], adjt[2*N];
 
int v (int x) { return 2*x; }
int nv (int x) { return 2*x+1; }
 
void add (int a, int b) {
    adj[a^1].push_back(b);
    adj[b^1].push_back(a);
    adjt[b].push_back(a^1);
    adjt[a].push_back(b^1);
 
}
 
void dfs (int x) {
    vis[x] = 1;
    for (auto v :adj[x]) if (!vis[v]) dfs(v);
    ord[ordn++] = x;
}
 
void dfst (int x) {
    cmp[x] = cnt, vis[x] = 0;
    for(auto v : adjt[x]) if (vis[v]) dfst(v);
}
 
bool run2sat() {
    for (int i = 1; i <= n; i++) {
        if (!vis[v(i)]) dfs(v(i));
        if (!vis[nv(i)]) dfs(nv(i));
    }
    for (int i = ordn-1; i >= 0; i--)
        if (vis[ord[i]]) cnt++, dfst(ord[i]);
    for (int i = 1; i <= n; i++) {
        if (cmp[v(i)] == cmp[nv(i)]) return false;
        val[i] = cmp[v(i)] > cmp[nv(i)];
    }
    return true;
}
 
int main () {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        int an, bn, cn;
        char al, bl, cl;
        scanf(" %d %c %d %c %d %c", &an, &al, &bn, &bl, &cn, &cl);
 
        int av, nav;
        if (al == 'R') av = v(an),  nav = nv(an);
        else           av = nv(an), nav = v(an);
 
        int bv, nbv;
        if (bl == 'R') bv = v(bn),  nbv = nv(bn);
        else           bv = nv(bn), nbv = v(bn);
 
        int cv, ncv;
        if (cl == 'R') cv = v(cn),  ncv = nv(cn);
        else           cv = nv(cn), ncv = v(cn);
 
        add(av, bv);
        add(av, cv);
 
        add(bv, av);
        add(bv, cv);
 
        add(cv, av);
        add(cv, bv);
    }
 
    bool ok = run2sat();
    if (ok) {
        for (int i = 1; i <= n; i++) printf("%c", val[i] ? 'R' : 'B');
    } else printf("-1");
    printf("\n");
    return 0;
}
