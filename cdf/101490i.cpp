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

int cmp[N];
vector <ll> p;

void primes () {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j <= N; j += i) cmp[j] = 1;
        p.pb(i);
    }
}

ll n;

int main () {
    primes();
    scanf("%lld", &n);
    if (n == 1) return 0*printf("no\n");
    for (ll x : p) {
        for (ll r = x; r <= n; r *= x) {
            if (r == n) return 0*printf("yes\n");
        }
    }
    for (ll x : p) {
        if (n % x == 0) return 0*printf("no\n");
    }
    printf("yes\n");
    return 0;
}
