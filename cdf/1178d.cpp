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
const int N = 1e6+5;

int cmp[N];
set <int> pr;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j+=i) cmp[j]=1;
        pr.insert(i);
    }
}

int n, x, y;

set <pii> ans;

int main () {
    scanf("%d", &n);
    primes();
    if (n < 3) {
        printf("-1\n");
        return 0;
    }
    int m = 0;
    while (!pr.count((m+2*n)/2)) m += 2;
    x = n-m;
    y = m;
    m = (2*x + 3*y)/2;
    for (int i = 1; i < n; i++) ans.insert({i, i+1});
    ans.insert({1, n});
    for (int i = 1; i <= n; i += 4) {
        if (y >= 2) ans.insert({i,   i+2}),   y -= 2;
        if (y >= 2) ans.insert({i+1, i+3}),   y -= 2;
    }
    printf("%d\n", (int) ans.size());
    for (auto p : ans) {
        printf("%d %d\n", p.st, p.nd);
    }
    return 0;
}
