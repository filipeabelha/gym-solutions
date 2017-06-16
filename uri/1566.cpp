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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

int tc, n, x, v[250], lasti;

int main () {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        cl(v, 0);
        lasti = -1;
        while (n--) {
            scanf("%d", &x);
            v[x]++;
            lasti = max(lasti, x);
        }
        for (int i = 20; i <= 230; i++) while (v[i]--)
            printf("%d%s", i, i == lasti and !v[i] ? "\n" : " ");
    }
    return 0;
}
