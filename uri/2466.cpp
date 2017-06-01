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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e2;

int n, m[N][N];

int main () {
    scanf("%d", &n);
    for (int j = 1; j <= n; j++) scanf("%d", &m[1][j]);
    for (int i = 2; i <= n; i++)
        for (int j = i; j <= n; j++)
            m[i][j] = m[i-1][j-1]*m[i-1][j];
    printf("%s\n", m[n][n] == 1 ? "preta" : "branca");
    return 0;
}
