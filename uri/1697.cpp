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

int t, n, x;

int cmp[N];
vi p;

void primes() {
    for (ll i = 2; i*i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j+=i) cmp[j]=1;
    }
    for (ll i = 1; i < N; i++) if (!cmp[i]) p.pb(i);
}

int main () {
    primes();

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        set <int> s;
        while (n--) {
            scanf("%d", &x);
            s.insert(x);
        }
        for (auto k : p) if (!s.count(k)) {
            printf("%d\n", k-1);
            break;
        }
    }
    return 0;
}
