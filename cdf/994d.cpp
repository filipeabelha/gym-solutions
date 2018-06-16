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

map <int, set<int> > a, b;
int n, m;
int x, y;

int main () {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);
        a[x].insert(y);
        a[y].insert(x);
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        b[x].insert(y);
        b[y].insert(x);
    }

    int ans = 0;
    set <int> s;

    for (auto p : a) {
        int x = p.st;
        for (auto y : p.nd) {
            int ok = 0;
            int foo = 0;
            if (b[x].size() - b[x].count(y) > 0) ok++, foo = x;
            if (b[y].size() - b[y].count(x) > 0) ok++, foo = y;
            if (ok == 2) ans = -1;
            if (ok == 1 and ans >= 0) {
                ans++;
                s.insert(foo);
            }
        }
    }

    for (auto p : b) {
        int x = p.st;
        for (auto y : p.nd) {
            int ok = 0;
            int foo = 0;
            if (a[x].size() - a[x].count(y) > 0) ok++, foo = x;
            if (a[y].size() - a[y].count(x) > 0) ok++, foo = y;
            if (ok == 2) ans = -1;
            if (ok == 1 and ans >= 0) {
                ans++;
                s.insert(foo);
            }
        }
    }

    if (ans == -1) return printf("-1\n"), 0;
    if (s.size() == 1) return printf("%d\n", *s.begin()), 0;
    printf("0\n");
    return 0;
}
