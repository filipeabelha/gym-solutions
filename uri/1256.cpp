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

int tc, n, m, x;
vi freq[N];

int main () {
    scanf("%d", &tc);
    while (tc--) {
        cl(freq, 0);
        scanf("%d%d", &m, &n);
        while (n--) {
            scanf("%d", &x);
            freq[x%m].pb(x);
        }
        for (int i = 0; i < m; i++) {
            printf("%d -> ", i);
            for (auto x : freq[i]) printf("%d -> ", x);
            printf("\\\n");
        }
        if (tc) printf("\n");
    }
    return 0;
}
