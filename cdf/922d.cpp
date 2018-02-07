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

typedef pair <string, pll> T;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;
char t[N];
vector <T> v;
string ans;
ll hh[N];
ll x;

int main () {
    scanf("%d", &n);
    while (n--) {
        ll s = 0;
        ll h = 0;
        scanf(" %s", t);
        int sz = strlen(t);
        for (int i = 0; i < sz; i++) {
            s += (t[i] == 's');
            h += (t[i] == 'h');
        }
        v.pb(mp(t, mp(s, h)));
    }
    sort(v.begin(), v.end(), [](T a, T b) {
         ll u = a.nd.st * b.nd.nd;
         ll v = b.nd.st * a.nd.nd;
         return u > v;
         });
    for (auto p : v) ans += p.st;
    for (int i = ans.size(); i >= 1; i--) hh[i] = hh[i+1] + (ans[i-1] == 'h');
    for (int i = 1; i <= ans.size(); i++) if (ans[i-1] == 's') x += hh[i];
    printf("%lld\n", x);
    return 0;
}
