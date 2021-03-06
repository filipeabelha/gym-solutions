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
const int N = 1e5+5;

int n, k, v[N], ans = INF;

int main () {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v, v+n);
    for (int i = 0; i <= k; i++) ans = min(ans, v[i+n-k-1]-v[i]);
    printf("%d\n", ans);
    return 0;
}
