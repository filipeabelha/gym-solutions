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

struct minQueue {
    deque <ll> d;
    queue <ll> q;

    void init () {
        while (d.size()) d.pop_front();
        while (q.size()) q.pop();
    }

    void push (ll x) {
        q.push(x);
        while (d.size() and d.back() > x) d.pop_back();
        d.push_back(x);
    }

    void pop () {
        if (q.size() and q.front() == d.front()) d.pop_front();
        q.pop();
    }

    ll mini () {
        if (!d.size()) return -1;
        return d.front();
    }
};


ll n, c, v[N];

ll sum;
minQueue m;

vector <ll> mins;

int main () {
    scanf("%lld%lld", &n, &c);
    for (int i = 0; i < n; i++) scanf("%lld", &v[i]), sum += v[i];
    if (n >= c) {
        for (int i = 0; i < c; i++) m.push(v[i]);
        mins.pb(m.mini());
        for (int i = c; i < n; i++) {
            m.push(v[i]);
            m.pop();
            mins.pb(m.mini());
        }
        vector <ll> ans(N);
        ll maxi = ans[0] = mins[0];
        for (int i = 1; i < min(c, (ll) mins.size()); i++)
            ans[i] = max(ans[i-1], mins[i]), maxi = max(maxi, ans[i]);
        for (int i = c; i < mins.size(); i++)
            ans[i] = max(ans[i-1], mins[i]+ans[i-c]), maxi = max(maxi, ans[i]);
        sum -= maxi;
    }
    printf("%lld\n", sum);
    return 0;
}
