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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e6+5;

struct maxQueue {
    deque <ll> d;
    queue <ll> q;

    void init () {
        while (d.size()) d.pop_front();
        while (q.size()) q.pop();
    }

    void push (ll x) {
        q.push(x);
        while (d.size() and d.back() < x) d.pop_back();
        d.push_back(x);
    }

    void pop () {
        if (q.size() and q.front() == d.front()) d.pop_front();
        q.pop();
    }

    ll maxi () {
        if (!d.size()) return -1;
        return d.front();
    }
};


ll n, p, d, ans, sum, v[N], s[N];
maxQueue m;

int main () {
    scanf("%lld%lld%lld", &n, &p, &d);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &v[i]);
        if (i <= d) s[d] += v[i];
        else        s[i] = s[i-1] + v[i] - v[i-d];
    }

    ans = d;
    m.push(s[d]);
    for (int i = 1; i <= d; i++) sum += v[i];

    ll l = 1, r = d;

    while (r < n) {
        r++;
        m.push(s[r]);
        sum += v[r];

        if (sum-m.maxi() <= p) ans = max(ans, r-l+1);

        while (sum-m.maxi() > p) {
            sum -= v[l];
            l++;
            m.pop();
        }
    }

    printf("%lld\n", ans);

    return 0;
}
