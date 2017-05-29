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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

const int N = 30;
int vis[N], tc, n, e, comp;
vii adj(N);
char chr;
priority_queue <char> pq;

void dfs(int x) {
    vis[x] = 1;
    pq.push(-x-97);
    for (int i = 0; i < adj[x].size(); i++)
        if (!vis[adj[x][i]])
            dfs(adj[x][i]);
}

int main () {
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        cl(vis, 0);
        for (int i = 0; i < N; i++) adj[i].clear();
        comp = 0;

        scanf("%d%d%c", &n, &e, &chr);

        for (int i = 0; i < e; i++) {
            char a, b;
            scanf("%c%c%c%c", &a, &chr, &b, &chr);
            a -= 97; b -= 97;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        printf("Case #%d:", t);

        for (int i = 0; i < n; i++)
            if (!vis[i]) {
                comp++;
                printf("\n");
                dfs(i);
                while (!pq.empty()) printf("%c,", -pq.top()), pq.pop();
            }

        printf("\n%d connected components\n\n", comp);
    }
    return 0;
}
