#include <bits/stdc++.h>
using namespace std;

#define cl(x, v) memset((x), (v), sizeof(x))
#define pb push_back

typedef vector <int> vi;
typedef vector <vi> vii;

const int N = 1e2+10;
const int K = 1e4;
const int INF = 0x3f3f3f3f;

vii adj(N);
int ans, n, amount, v[N], coin[K];
int r, k, a, b;

int main () {
    while (~scanf("%d%d", &r, &k)) {
        for (int i = 0; i < N; i++) adj[i].clear();
        for (int i = 0; i < k; i++) {
            scanf("%d%d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        cl(v, 0); cl(coin, 63);
        coin[0] = 0;
        for (int i = 0; i < r; i++) v[i] = adj[i].size();
        for (int i = 0; i < r; i++)
            for (int j = K-1; j >= v[i]; j--)
                coin[j] = min(coin[j], 1+coin[j-v[i]]);
        ans = coin[k];
        printf("%s\n", (ans < INF) ? "S" : "N");
    }
}
