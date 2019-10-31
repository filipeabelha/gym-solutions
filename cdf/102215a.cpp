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
const int N = 5e5+5;

int n, v[N], f[N][2];
// f[N][0]: neg[N]
// f[N][1]: pos[N]

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    int i = 0, j = 0;
    f[abs(v[0])][(v[0] > 0)]++;
    while (j+1 < n and not (v[j+1] > 0 and f[v[j+1]][0] > 0)) {
        j++;
        f[abs(v[j])][(v[j] > 0)]++;
    }
    printf("%d ", j-i+1);
    for (int k = 1; k < n; k++) {
        f[abs(v[i])][(v[i] > 0)]--;
        i++;
        while (j+1 < n and not (v[j+1] > 0 and f[v[j+1]][0] > 0)) {
            j++;
            f[abs(v[j])][(v[j] > 0)]++;
        }
        printf("%d ", j-i+1);
    }
    printf("\n");
    return 0;
}
