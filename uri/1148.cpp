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
const int N = 5e2+10;

int dist[N][N];
int n1, n2, s, strt, vert, edges, queries, a, b;

void floyd () {
    cl(dist, 63);
    for (int i = 0; i < edges; i++) {
        scanf(" %d%d%d" , &n1, &n2, &s);
        if (dist[n2][n1] < INF) dist[n1][n2] = 0, dist[n2][n1] = 0;
        else                    dist[n1][n2] = s;
    }

    for (int i = 0; i <= vert; i++)
        dist[i][i] = 0;
    for (int k = 0; k <= vert; k++)
        for (int i = 0; i <= vert; i++)
            for (int j = 0; j <= vert; j++)
                dist[i][j] = min(dist[i][k]+dist[k][j], dist[i][j]);
}


int main () {
    while (1) {
        scanf("%d%d", &vert, &edges);
        if (!vert and !edges) break;
        floyd();
        scanf("%d", &queries);
        while (queries--) {
            scanf("%d%d", &a, &b);
            if (dist[a][b] == INF) printf("Nao e possivel entregar a carta\n");
            else printf("%d\n", dist[a][b]);
        }
        printf("\n");
    }
    return 0;
}
