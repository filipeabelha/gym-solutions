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
const int N = 2e5+5;

int q, n, v[N][2];
char c;

int main () {
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf(" %c", &c), v[i][0] = c-'0';
        for (int i = 1; i <= n; i++) scanf(" %c", &c), v[i][1] = c-'0';
        for (int i = 1; i <= n; i++) v[i][0] = v[i][0] > 2;
        for (int i = 1; i <= n; i++) v[i][1] = v[i][1] > 2;
        int i = 1, j = 0;
        int ok = 1;
        while (1) {
            if (!v[i][j]) i++;
            else if (v[i][j] and v[i][j^1]) i++, j ^= 1;
            else if (v[i][j] and !v[i][j^1]) {
                ok = 0;
                break;
            }
            if (i == n+1) break;
        }
        if (!j) ok = 0;
        printf("%s\n", ok ? "YES" : "NO");
    }

    return 0;
}
