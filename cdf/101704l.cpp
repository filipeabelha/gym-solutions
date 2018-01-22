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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LMOD = 1011112131415161719ll;
const int N = 1e2+5;

int vert, edges, a, b, d, di;
int dist[N][N];
long double ans;

void floyd(){
    cl(dist, 63);
    for (int i = 0; i < edges; i++) {
        scanf("%d%d%d", &a, &b, &d);
        dist[a][b] = d;
    }
    for (int i = 1; i <= vert; i++) dist[i][i] = 0;
    for (int k = 0; k <= vert; k++)
        for (int i = 0; i <= vert; i++)
            for (int j = 0; j <= vert; j++)
                dist[i][j] = min(dist[i][k]+dist[k][j], dist[i][j]);
}

int main () {
    scanf("%d%d", &vert, &edges);
    floyd();
    for (int i = 1; i <= vert; i++) {
        for (int j = 1; j <= vert; j++) {
            if (dist[i][j] > 0 and dist[i][j] < INF) {
                ans += dist[i][j];
                di++;
            }
        }
    }
    ans /= di;
    printf("%.6Lf\n", ans);
    return 0;
}
