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
const int N = 1e3+5;

int n;
char t[N][N];

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) t[i][j] = 'D';

    for (int i = 1; i <= n/2; i++) {
        for (int j = 1; j <= n/2-i+1; j++) t[i][j] = t[n-i+1][j] = '*';
        for (int j = 1; j <= n/2-i+1; j++) t[i][n-j+1] = t[n-i+1][n-j+1] = '*';
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) printf("%c%s", t[i][j], (j == n) ? "\n" : "");
    return 0;
}
