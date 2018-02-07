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

int n, cnt, x, y, a, b;
map <int, int> f;

int main () {
    while (~scanf("%d", &n) and n and ++cnt) {
        f.clear();
        x = y = 0;

        while (n--) {
            scanf("%d%d", &a, &b);
            x += a;
            y += b;
            f[b/a] += a;
        }

        int fst = 1;
        printf("%sCidade# %d:\n", cnt > 1 ? "\n" : "", cnt);
        for (auto p : f) {
            printf("%s%d-%d", fst ? "" : " ", p.nd, p.st);
            fst = 0;
        }
        printf("\nConsumo medio: %.2Lf m3.\n", floor(100*(long double)y/x)/100);
    }
    return 0;
}
