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

int n, m, a[N], b[N], rch[N];
int maxi;

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
    for (int i = 1; i <= n; i++) {
        int ok = 0;
        for (int j = 0; j < i; j++) if (!rch[j] and b[j] >= a[i]) {
            ok = 1;
            maxi = max(maxi, b[i]);
        }
        if (!ok) rch[i] = 1;
    }
    printf("%s\n", maxi >= m ? "YES" : "NO");
    return 0;
}
