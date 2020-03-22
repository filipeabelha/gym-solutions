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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int t;
map <int, ll> m;

int main () {
    scanf("%d", &t);
    while (t--) {
        m.clear();

        ll a, b;
        scanf("%lld%lld", &a, &b);
        while (a--) {
            ll x;
            scanf("%lld", &x);
            m[x] += x;
        }

        vector <pll> v;
        for (auto p : m) v.pb({-p.nd, -p.st});
        sort(v.begin(), v.end());
        for (auto& p : v) {
            p.st *= -1;
            p.nd *= -1;
        }

        ll cur = 0;
        vl ans;
        for (int i = 0; i < v.size(); i++) {
            cur += v[i].st;
            ans.pb(v[i].nd);
            if (cur >= b) break;
        }
        if (cur >= b) {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                printf("%lld%c", ans[i], " \n"[i+1==ans.size()]);
        } else printf("Impossible\n");

    }

    return 0;
}
