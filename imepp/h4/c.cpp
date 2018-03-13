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

int cmp[N];
vector <ll> p;

void primes () {
    for (int i = 2; i*i < N; i++) if (!cmp[i])
        for (int j = i*i; j < N; j += i) cmp[j] = 1;
    for (int i = 2; i < N; i++) if (!cmp[i]) p.pb(i);
}

ll n;

int main () {
    primes();
    while (~scanf("%lld", &n) and n) {
        printf("%lld = ", n);
        set <ll> v;
        for (int i = 0; p[i]*p[i] < n; i++) {
            while (n % p[i] == 0) {
                n /= p[i];
                v.insert(p[i]);
            }
        }
        if (n > 1) v.insert(n);
        printf("%lld", *v.begin()); v.erase(v.begin());
        for (auto c : v) printf(" x %lld", c);
        printf("\n");
    }
    return 0;
}
