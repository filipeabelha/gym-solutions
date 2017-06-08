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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e6+10;

int cmp[N], n;
set <ll> pr;
ll x;

int main () {
    for (ll i = 2; i <= N; ++i) if (!cmp[i]) {
        for (ll j = i*i; j <= N; j+=i) cmp[j] = 1;
        pr.insert(i*i);
    }
    scanf("%d", &n);
    while (n--) scanf("%lld", &x), printf("%s\n", pr.count(x) ? "YES" : "NO");
    return 0;
}
