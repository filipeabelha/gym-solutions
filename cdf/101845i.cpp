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

ll n, m, x, k;
deque <ll> ans;

void shift () {
    ans.clear();
    while (x) {
        if (x&1) ans.push_back(1);
        else ans.push_back(0);
        x >>= 1;
    }
    while (ans.size() < n) ans.push_back(0);
    for (int i = 0; i < k; i++) {
        ans.push_front(ans.back());
        ans.pop_back();
    }
    ll cur = 0;
    ll mul = 1;
    while (ans.size()) {
        cur += mul*ans.front();
        mul <<= 1;
        ans.pop_front();
    }
    printf("%lld\n", cur);
}

int main () {
    scanf("%lld%lld", &n, &m);
    while (m--) {
        scanf("%lld%lld", &x, &k);
        k %= n;
        shift();
    }
    return 0;
}
