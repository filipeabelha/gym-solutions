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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e4+10;

int n, r, x, m[N], ok;

int main () {
    while (~scanf("%d%d", &n, &r)) {
        cl(m, 0); ok = 0;
        for (int i = 1; i <= r; i++)
            scanf("%d", &x), m[x] = 1;
        for (int i = 1; i <= n; i++)
            if (!m[i]) printf("%d ", i), ok = 1;
        printf("%s\n", ok ? "" : "*");
    }
    return 0;
}
