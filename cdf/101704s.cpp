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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LMOD = 1011112131415161719ll;
const int N = 1e5+5;

int n, a, b, ans, sub;
vector <pii> v;

int main () {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        v.pb(mp(min(a,b), 1));
        v.pb(mp(max(a,b), -1));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size()-1; i++) {
        sub += v[i].nd;
        if (sub > 0) ans += v[i+1].st-v[i].st;
    }
    printf("%d\n", ans);
    return 0;
}
