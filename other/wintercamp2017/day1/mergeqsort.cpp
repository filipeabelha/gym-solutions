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

int n;
map <int, ll> ans;

ll go (int x) {
    if (x == 1 or x == 0) return 0;
    if (!ans[x]) ans[x] = x + go(floor(sqrt(x))) + go(x-floor(sqrt(x)));
    return ans[x];
}


int main () {
    scanf("%d", &n);
    printf("%lld\n", go(n));
    return 0;
}
