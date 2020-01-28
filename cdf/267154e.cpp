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

int n, m, ans[N];
vector <pii> d;
vector <piii> v;

int main () {
    scanf("%d%d", &n, &m);
    d.resize(n);
    v.resize(m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i].st);
        d[i].st *= -1;
        d[i].nd = i+1;
    }
    for (int i = 0; i < m; i++) scanf("%d", &v[i].nd.st);
    for (int i = 0; i < m; i++) scanf("%d", &v[i].st);
    for (int i = 0; i < m; i++) v[i].nd.nd = i+1;

    sort(v.begin(), v.end());
    sort(d.begin(), d.end());

    for (auto& p : d) p.st *= -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[j].nd.st >= d[i].st) {
                v[j].nd.st = 0;
                ans[d[i].nd] = v[j].nd.nd;
                break;
            }
        }
        if (!ans[d[i].nd]) {
            printf("impossible\n");
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");

    return 0;
}
