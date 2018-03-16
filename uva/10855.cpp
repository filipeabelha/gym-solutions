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
#define gcd(x, y) __gcd((x), (y))

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

char a[N][N], b[N][N];
int n, m;
int u, v, w, x;

int main () {
    while (~scanf("%d%d", &n, &m) and n and m) {
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
            scanf(" %c", &a[i][j]);
        for (int i = 0; i < m; i++) for (int j = 0; j < m; j++)
            scanf(" %c", &b[i][j]);

        u = v = w = x = 0;
        for (int s = 0; s < n-m+1; s++) for (int t = 0; t < n-m+1; t++) {
            int ok = 1;
            for (int J = 0; J < m; J++) for (int I = m-1; I >= 0; I--) {
                int x = a[s+I][t+J];
                int y = b[I][J];
                if (x != y) ok = 0;
            }
            if (ok) u++;

            ok = 1;
            for (int J = 0; J < m; J++) for (int I = m-1; I >= 0; I--) {
                int x = a[s+J][t+(m-1-I)];
                int y = b[I][J];
                if (x != y) ok = 0;
            }
            if (ok) v++;

            ok = 1;
            for (int I = m-1; I >= 0; I--) for (int J = m-1; J >= 0; J--) {
                int x = a[s+(m-1-I)][t+(m-1-J)];
                int y = b[I][J];
                if (x != y) ok = 0;
            }
            if (ok) w++;

            ok = 1;
            for (int J = m-1; J >= 0; J--) for (int I = 0; I < m; I++) {
                int x = a[s+(m-1-J)][t+I];
                int y = b[I][J];
                if (x != y) ok = 0;
            }
            if (ok) x++;
        }
        printf("%d %d %d %d\n", u, v, w, x);
    }
    return 0;
}
