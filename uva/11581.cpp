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
#define gcd(x, y) __gcd((x), (y))

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

int n, f[5][5], g[5][5];

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};

bool go () {
    cl(g, 0);
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            for (int k = 0; k < 4; k++) {
                int x = i+dx[k];
                int y = j+dy[k];
                if (x < 1 or x > 3) continue;
                if (y < 1 or y > 3) continue;
                g[i][j] ^= f[x][y];
            }
    swap(f, g);
}

bool chk () {
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            if (f[i][j]) return true;
    return false;
}

int slv () {
    int ans = -1;
    while (chk()) go(), ans++;
    return ans;
}

int main () {
    scanf("%d", &n);
    while (n--) {
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                scanf("%1d", &f[i][j]);

        printf("%d\n", slv());
    }
    return 0;
}
