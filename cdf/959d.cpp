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
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const ll INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e6+100;

ll n, a[N], cmp[N];
vector <ll> p;
vector <ll> factors[N];
set <ll> s;
int ok;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i; j < N; j+=i) {
            cmp[j]=1;
            factors[j].pb(i);
        }
        p.pb(i);
        s.insert(i);
    }
}

bool possible (ll n) {
    for (auto f : factors[n]) if (!s.count(f)) return false;
    return true;
}

int main () {
    primes();
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (ll i = 1; i <= n; i++) {
        if (!ok) {
            for (ll j = a[i]; ; j++) {
                if (!possible(j)) continue;
                printf("%lld ", j);
                if (j > a[i]) ok = 1;
                for (auto f : factors[j]) s.erase(f);
                break;
            }
        } else {
            printf("%lld ", *s.begin());
            s.erase(s.begin());
        }
    }
    printf("\n");
    return 0;
}
