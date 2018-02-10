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

ll n, m, r, k, ans;

ll f (ll x, ll y) {
    return (min(n+1, x+r)-max(x, r))*(min(m+1, y+r)-max(y, r));
}

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};

priority_queue <pair <ll, pll> > pq;
map <pll, int> vis;

int main () {
    scanf("%lld%lld%lld%lld", &n, &m, &r, &k);

    ll t = (n-r+1)*(m-r+1);

    pll p = mp((n+1)/2, (m+1)/2);
    pq.push(mp(f(p.st, p.nd), p));
    vis[p] = 1;

    ll cnt = k;
    while (pq.size() and cnt) {
        ll v = pq.top().st;
        pll z = pq.top().nd; pq.pop();
        ans += v;
        for (int i = 0; i < 4; i++) {
            ll x = z.st + dx[i];
            ll y = z.nd + dy[i];
            if (vis[mp(x, y)]) continue;
            if (x < 1 or x > n) continue;
            if (y < 1 or y > m) continue;
            vis[mp(x, y)] = 1;
            pq.push(mp(f(x, y), mp(x, y)));
        }
        cnt--;
    }

    printf("%.10Lf\n", (ld) ans/t);
    return 0;
}
