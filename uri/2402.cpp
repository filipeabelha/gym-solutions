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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e5+10;

ll n, cmp[N], p[N], cnt;

int main () {
    scanf("%lld", &n);
    for (ll i = 2; i < N; ++i) if (!cmp[i]) {
        for (ll j = i*i; j < N; j+=i) cmp[j] = 1;
        p[cnt++] = i;
    }
    int ok = 0;
    for (int i = 0; p[i]*p[i] <= n; i++) {
        if (n % p[i] == 0) {
            ok = 1;
            break;
        }
    }
    printf("%s\n", ok ? "S" : "N");
    return 0;
}
