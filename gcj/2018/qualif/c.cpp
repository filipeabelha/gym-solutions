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
const int N = 1e3+5;

int t, a, x, y, m[N][N];

int dx[] = {+0, +0, +0, +1, +1, +1, -1, -1, -1};
int dy[] = {+1, +0, -1, +1, +0, -1, +1, +0, -1};

bool chk (int i, int j) {
    for (int k = 0; k < 9; k++)
        if (!m[i+dx[k]][j+dy[k]]) return false;
    return true;
}

int main () {
    scanf("%d", &t);
    while (t--) {
        cl(m, 0);
        scanf("%d", &a);
        int s = a/3 + (a % 3 > 0);
        for (int i = 2; i <= s+1; i += 3) {
            while (!chk(i, 10)) {
                printf("%d %d\n", i, 10);
                fflush(stdout);
                scanf("%d%d", &x, &y);
                assert(x >= 0 and y >= 0);
                if (!x and !y) break;
                m[x][y] = 1;
            }
            if (!x and !y) break;
        }
    }
    return 0;
}
