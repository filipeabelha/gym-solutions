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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e2+10;

int n, x[N], y[N], r[N], a, b, vert, q;
double dist[N][N];

int dis (int x1, int x2, int y1, int y2) {
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void floyd () {
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        dist[i][j] = (double) INF;
    for (int i = 1; i <= vert; i++) for (int j = 1; j <= vert; j++)
        if (i != j and dis(x[i], x[j], y[i], y[j]) <= r[i]*r[i])
            dist[i][j] = sqrt(dis(x[i], x[j], y[i], y[j]));
    for (int i = 0; i <= vert; i++)
        dist[i][i] = 0;
    for (int k = 0; k <= vert; k++)
        for (int i = 0; i <= vert; i++)
            for (int j = 0; j <= vert; j++)
                dist[i][j] = min(dist[i][k]+dist[k][j], dist[i][j]);
}


int main () {
    while (1) {
        scanf("%d", &vert); if (!vert) break;
        for (int i = 1; i <= vert; i++) scanf("%d%d%d", &x[i], &y[i], &r[i]);
        floyd();
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d", &a, &b);
            printf("%d\n", dist[a][b] < INF ? (int) dist[a][b] : -1);
        }
    }
    return 0;
}
