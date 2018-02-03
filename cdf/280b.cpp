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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int t, sx, sy, ex, ey, ans = INF;
char dirs[N];

int main () {
    scanf("%d%d%d%d%d", &t, &sx, &sy, &ex, &ey);
    scanf(" %s", dirs);
    for (int i = 1; i <= t; i++) {
        if (dirs[i-1] == 'S' and ey < sy) sy--;
        if (dirs[i-1] == 'N' and ey > sy) sy++;
        if (dirs[i-1] == 'W' and ex < sx) sx--;
        if (dirs[i-1] == 'E' and ex > sx) sx++;
        if (sx == ex and sy == ey) ans = min(ans, i);
    }
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}
