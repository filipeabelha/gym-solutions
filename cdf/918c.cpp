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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 5e3+5;

char s[N];
int sz, ans;
int f[N][N], g[N][N];

int main () {
    scanf("%s", s);
    sz = strlen(s);

    for (int l = 0; l < sz; l++) {
        int cur = 0;
        int ok = 1;
        for (int r = l; r < sz; r++) {
            cur += (s[r] == ')' ? -1 : 1);
            if (cur < 0) ok = 0;
            f[l][r] = ok;
        }
    }

    for (int r = sz-1; r >= 0; r--) {
        int cur = 0;
        int ok = 1;
        for (int l = r; l >= 0; l--) {
            cur += (s[l] == '(' ? -1 : 1);
            if (cur < 0) ok = 0;
            g[l][r] = ok;
        }
    }

    for (int i = 0; i < sz; i++) for (int j = i+1; j < sz; j += 2)
        if (f[i][j] and g[i][j]) ans++;

    printf("%d\n", ans);

    return 0;
}
