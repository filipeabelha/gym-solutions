#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 5e2+5;
const int M = 1e5+5;

int dist[N][N], n, x;
char s[M], t[M], a, b;

int main () {
    scanf(" %s %s %d", s, t, &n);

    cl(dist, 63);
    for (int i = 0; i < N; i++) dist[i][i] = 0;

    while (n--) {
        scanf(" %c %c %d", &a, &b, &x);
        dist[a][b] = min(dist[a][b], x);
    }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    int y = strlen(s);

    ll ans = 0;

    for (int i = 0; i < y; i++) {
        ans += dist[s[i]][t[i]];
        if (ans > INF/2) {
            printf("-1\n");
            return 0;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
