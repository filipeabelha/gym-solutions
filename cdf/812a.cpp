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

int l, m[4][4], ans[4], ok = 1;

int main () {
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
        scanf("%d", &m[i][j]);
        if (j == 3) continue;
        ans[(i+3-j)%4] |= m[i][j];
        ans[i] |= m[i][j];
    }
    for (int i = 0; i < 4; i++) if (m[i][3] and ans[i]) ok = 0;
    printf("%s\n", ok ? "NO" : "YES");
    return 0;
}
