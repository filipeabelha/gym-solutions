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
const int N = 1e2+5;

char t[N][N];
int a[N][N];

int k, n;

int main () {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf(" %c", &t[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n-k+1; j++) {
            int ok = 1;
            for (int z = 0; z < k; z++) {
                if (t[i][j+z] == '#') ok = 0;
            }
            if (!ok) continue;
            for (int z = 0; z < k; z++) a[i][j+z]++;
        }

    for (int i = 1; i <= n-k+1; i++)
        for (int j = 1; j <= n; j++) {
            int ok = 1;
            for (int z = 0; z < k; z++)
                if (t[i+z][j] == '#') ok = 0;
            if (!ok) continue;
            for (int z = 0; z < k; z++) a[i+z][j]++;
        }

    int x = 1;
    int y = 1;
    int z = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (z < a[i][j]) {
                z = a[i][j];
                x = i;
                y = j;
            }
        }
    }

    printf("%d %d\n", x, y);
    return 0;
}
