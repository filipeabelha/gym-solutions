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
const int N = 5e2+5;

int n, a[N][N][4], m[N][N], ans = INF;

int main () {
    scanf("%d", &n);
    for (int k = 0; k < 4; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%1d", &a[i][j][k]);

    vi v = {0, 1, 2, 3};
    do {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                m[i][j] = a[i][j][v[0]];

        for (int i = n+1; i <= 2*n; i++)
            for (int j = 1; j <= n; j++)
                m[i][j] = a[i-n][j][v[1]];

        for (int i = 1; i <= n; i++)
            for (int j = n+1; j <= 2*n; j++)
                m[i][j] = a[i][j-n][v[2]];

        for (int i = n+1; i <= 2*n; i++)
            for (int j = n+1; j <= 2*n; j++)
                m[i][j] = a[i-n][j-n][v[3]];

        /*for (int i = 1; i <= 2*n; i++)
            for (int j = 1; j <= 2*n; j++)
                printf("%d%c", m[i][j], " \n"[j==2*n]);
        printf("\n");*/

        int sum = 0;
        for (int i = 1; i <= 2*n; i += 2)
            for (int j = 1; j <= 2*n; j += 2)
                sum += (m[i][j] != 1);
        for (int i = 2; i <= 2*n; i += 2)
            for (int j = 2; j <= 2*n; j += 2)
                sum += (m[i][j] != 1);

        for (int i = 1; i <= 2*n; i += 2)
            for (int j = 2; j <= 2*n; j += 2)
                sum += (m[i][j] != 0);
        for (int i = 2; i <= 2*n; i += 2)
            for (int j = 1; j <= 2*n; j += 2)
                sum += (m[i][j] != 0);
        ans = min(ans, sum);

        sum = 0;
        for (int i = 1; i <= 2*n; i += 2)
            for (int j = 1; j <= 2*n; j += 2)
                sum += (m[i][j] != 0);
        for (int i = 2; i <= 2*n; i += 2)
            for (int j = 2; j <= 2*n; j += 2)
                sum += (m[i][j] != 0);

        for (int i = 1; i <= 2*n; i += 2)
            for (int j = 2; j <= 2*n; j += 2)
                sum += (m[i][j] != 1);
        for (int i = 2; i <= 2*n; i += 2)
            for (int j = 1; j <= 2*n; j += 2)
                sum += (m[i][j] != 1);
        ans = min(ans, sum);
    } while (next_permutation(v.begin(), v.end()));
    printf("%d\n", ans);
    return 0;
}
