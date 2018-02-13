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
const int N = 1e5+5;
const int S = 1000;

int n;
int p[200][S];

void solve () {
    p[0][0] = p[1][1] = 1;
    for (int i = 2; i < 200; i++) {
        p[i][0] = p[i-2][0];
        for (int j = 1; j < S; j++)
            p[i][j] = (p[i-1][j-1] + p[i-2][j])%2;
    }
}

int main () {
    scanf("%d", &n);

    solve();

    printf("%d\n", n);
    for (int j = 0; j <= n; j++) printf("%d ", p[n][j]);
    printf("\n");

    printf("%d\n", n-1);
    for (int j = 0; j <= n-1; j++) printf("%d ", p[n-1][j]);
    printf("\n");

    return 0;
}
