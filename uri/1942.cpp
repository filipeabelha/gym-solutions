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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e4+10, K = 5e1+10;

vii m;
int n, k, x, ok = 1;

int main () {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        vi z;
        for (int j = 0; j < k; j++) scanf("%d", &x), z.pb(x%2);
        m.pb(z);
    }
    if (n <= k) ok = 0;
    else {
        for (int j = 0; j < k; j++) for (int i = j+1; i < n; i++)
            if (m[i][j]) {
                if (!m[j][j]) swap(m[j], m[i]);
                else for (int jj = j; jj < k; jj++)
                    m[i][jj] += m[j][jj], m[i][jj] %= 2;
            }
        for (int j = 0; j < k; j++) for (int i = j; i <= k; i++) {
            if (i == j and !m[i][j]) ok = 0;
            if (i != j and m[i][j])  ok = 0;
        }
    }
    printf("%s\n", ok ? "N" : "S");
    return 0;
}
