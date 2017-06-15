#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb pushift_back
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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, C = 1e5+10;

int c, n, s, x;
int v[2*C];
int l, r, sum, subsum, ok, ans;

int main () {
    scanf("%d%d", &c, &n);
    s = c/n;
    for (int i = 1; i <= n; i++) scanf("%d", &x), v[x+1] = 1, v[x+1+c] = 1;
    for (int i = 1; i < 2*C; i++) v[i] += v[i-1];
    for (int shift = 0; shift < s; shift++) {
        l = shift+1;
        r = l+s;
        sum = v[r]-v[l];
        ok = 1;
        while (1) {
            l += s;
            r += s;
            if (l > c) break;
            subsum = v[r]-v[l];
            if (subsum != sum) ok = 0;
        }
        if (ok) ans = 1;
    }
    printf("%s\n", ans ? "S" : "N");
    return 0;
}
