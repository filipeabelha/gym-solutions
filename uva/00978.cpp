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

int t, n, sg, sb, x;
multiset <int, greater<int> > g, b;

int main () {
    scanf("%d", &t);
    while (t--) {
        g.clear();
        b.clear();

        scanf("%d%d%d", &n, &sg, &sb);
        while (sg--) {
            scanf("%d", &x);
            g.insert(x);
        }
        while (sb--) {
            scanf("%d", &x);
            b.insert(x);
        }
        while (g.size() and b.size()) {
            vi addg;
            vi addb;
            for (int i = 0; i < n and g.size() and b.size(); i++) {
                int gg = *g.begin();
                int bb = *b.begin();
                g.erase(g.begin());
                b.erase(b.begin());
                if (gg > bb) addg.pb(gg-bb);
                if (gg < bb) addb.pb(bb-gg);
            }
            for (auto gg : addg) g.insert(gg);
            for (auto bb : addb) b.insert(bb);
        }
        if (g.size()) {
            printf("green wins\n");
            for (auto gg : g) printf("%d\n", gg);
        } else if (b.size()) {
            printf("blue wins\n");
            for (auto bb : b) printf("%d\n", bb);
        } else printf("green and blue died\n");
        if (t) printf("\n");
    }
    return 0;
}
