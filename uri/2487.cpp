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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

ll t, v[N];
int n;

int main () {
    while (~scanf("%lld%d", &t, &n)) {
        t -= n;
        for (int i = 0; i < n; i++) {
            ll x = 1;
            while (2*x > 0 and 2*x <= t+1) x *= 2;
            v[i] = x;
            t -= x-1;
        }
        v[0] += t;
        for (int i = 0; i < n; i++)
            printf("%lld%s", v[i], i < n-1 ? " " : "\n");
    }
    return 0;
}
