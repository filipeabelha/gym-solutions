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

set <int> s;
int n, x;
ll ans, cnt[N];

int main () {
    scanf("%d%d", &n, &x);
    for (int a, i = 0; i < n; i++) scanf("%d", &a), s.insert(a), cnt[a]++;
    for (auto i : s) if ((i^x) > 0 and (i^x) < N)
        ans += cnt[i]*(cnt[i^x]-(i == (i^x)));
    printf("%lld\n", ans/2);
    return 0;
}
