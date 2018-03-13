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

int t[10][10];
int n;
char ch;

int bk () {
    int r = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        if (!t[i][j]) {
            for (int k = j;   k <= n and t[i][k] < INF; k++) t[i][k]++;
            for (int k = j-1; k >= 1 and t[i][k] < INF; k--) t[i][k]++;
            for (int k = i-1; k <= n and t[k][j] < INF; k++) t[k][j]++;
            for (int k = i-1; k >= 1 and t[k][j] < INF; k--) t[k][j]++;

            r = max(r, 1+bk());

            for (int k = j;   k <= n and t[i][k] < INF; k++) t[i][k]--;
            for (int k = j-1; k >= 1 and t[i][k] < INF; k--) t[i][k]--;
            for (int k = i-1; k <= n and t[k][j] < INF; k++) t[k][j]--;
            for (int k = i-1; k >= 1 and t[k][j] < INF; k--) t[k][j]--;
    }
    return r;
}

int main () {
    while (~scanf("%d", &n) and n) {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
            scanf(" %c", &ch);
            t[i][j] = (ch == 'X' ? INF : 0);
        }
        printf("%d\n", bk());
    }
    return 0;
}
