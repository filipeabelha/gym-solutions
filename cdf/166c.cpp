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

int n, x, ok, ans;
vi v;

int med () {
    return v[(v.size()+1)/2-1];
}

int main () {
    scanf("%d%d", &n, &x);

    v.resize(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        if (v[i] == x) ok = 1;
    }

    if (!ok) v.pb(x), ans++;

    sort(v.begin(), v.end());

    while (x > med()) v.pb(INF),    ans++;
    while (x < med()) v.pop_back(), ans++;

    printf("%d\n", ans);

    return 0;
}
