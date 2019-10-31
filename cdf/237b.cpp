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
const int N = 1e5+5;

int n, k, c[N];
map <int, pii> coord;
map <pii, int> coordrev;
vector <pair<pii, pii> > ans;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c[i]; j++) {
            scanf("%d", &k);
            coord[k] = {i, j};
            coordrev[{i, j}] = k;
        }
    }

    k = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c[i]; j++) {
            int cur = coordrev[{i, j}];
            pii curp = coord[k];
            if (k != cur) {
                coordrev[{i, j}] = k;
                coord[k] = {i, j};

                coordrev[curp] = cur;
                coord[cur] = curp;
                ans.pb({{i, j}, curp});
            }
            k++;
        }
    }
    printf("%d\n", (int) ans.size());
    for (auto p : ans) {
        printf("%d %d %d %d\n", p.st.st, p.st.nd, p.nd.st, p.nd.nd);
    }


    return 0;
}

