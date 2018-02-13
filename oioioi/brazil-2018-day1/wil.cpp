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
const int N = 2e6+5;

struct maxQueue {
    deque <ll> d;
    queue <ll> q;

    void init() {
        while (d.size()) d.pop_back();
        while (q.size()) q.pop();
    }

    void push(ll x) {
        q.push(x);
        while (d.size() and d.back() < x) d.pop_back();
        d.pb(x);
    }

    void pop() {
        if (!d.size()) return;
        if (d.front() == q.front()) d.pop_front();
        q.pop();
    }

    ll maxi() {
        if (!d.size()) return -1;
        return d.front();
    }
};

ll n, p, d, w[N];

ll minSand (ll x) {
    if (d >= x) return 0;

    maxQueue q;
    ll sum = 0, curCover = 0, ans = LINF;

    for (int i = 1; i <= x; i++) sum += w[i];

    for (int i = 1; i <= d; i++) curCover += w[i];
    q.push(curCover);

    for (int i = d+1; i <= x; i++) {
        curCover += w[i];
        curCover -= w[i-d];
        q.push(curCover);
    }

    ans = min(ans, sum-q.maxi());

    for (int i = x+1; i <= n; i++) {
        sum += w[i];
        sum -= w[i-x];

        curCover += w[i];
        curCover -= w[i-d];

        q.push(curCover);
        q.pop();

        ans = min(ans, sum-q.maxi());
    }

    return ans;
}

ll solve (ll l, ll r) {
    ll ans;
    while (l < r) {
        ans = (l+r+1)/2;
        if (minSand(ans) > p) r = ans-1;
        else l = ans;
    }
    ans = (l+r+1)/2;
    return ans;
}

int main () {
    scanf("%lld%lld%lld", &n, &p, &d);
    for (int i = 1; i <= n; i++) scanf("%lld", &w[i]);
    printf("%lld\n", solve(0, n));
    return 0;
}
