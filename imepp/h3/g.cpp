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

int t, n, a, b, x;
vector <pair<string, pii> > d;
string s;
int fst;

int main () {
    scanf("%d", &t);
    while (t--) {
        if (fst) printf("\n");
        fst = 1;
        d.clear();
        scanf("%d", &n);
        while (n--) {
            cin >> s;
            scanf(" %d %d", &a, &b);
            d.pb(mp(s, mp(a, b)));

        }
        scanf("%d", &n);
        while (n--) {
            vector <string> ans;
            scanf("%d", &x);
            for (auto p : d) if (p.nd.st <= x and x <= p.nd.nd) ans.pb(p.st);
            printf("%s\n", ans.size() != 1 ? "UNDETERMINED" : ans[0].c_str());
        }
    }
    return 0;
}
