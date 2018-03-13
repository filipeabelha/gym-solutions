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

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

ll n, ans;
int cmp[N];
vector <ll> p;

void primes () {
    for (int i = 2; i*i < N; i++) if (!cmp[i])
        for (int j = i*i; j < N; j+=i) cmp[j] = 1;
    for (int i = 2; i < N; i++) p.pb(i);
}

int main () {
    primes();
    while (~scanf("%llu", &n)) {
        ans = n;
        for (int i = 0; p[i]*p[i] <= n; i++) {
            if (n % p[i] == 0) {
                ans *= p[i]-1;
                ans /= p[i];
            }
            while (n % p[i] == 0) n /= p[i];
        }
        if (n > 1) {
            ans *= n-1;
            ans /= n;
        }
        printf("%llu\n", ans/2);
    }
    return 0;
}
