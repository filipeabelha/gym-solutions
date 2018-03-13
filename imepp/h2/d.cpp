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

maxQueue m;
int t, n, k, x;

int main () {
    scanf("%d", &t);
    while (t--) {
        m.init();
        scanf("%d%d", &n, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &x);
            m.push(x);
        }
        printf("%lld ", m.maxi());
        for (int i = k; i < n; i++) {
            scanf("%d", &x);
            m.push(x);
            m.pop();
            printf("%lld ", m.maxi());
        }
        printf("\n");
    }
    return 0;
}
