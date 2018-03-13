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
const int N = 1e6+5;
const int M = 5e2+5;

int n, m, t[M][M];
int ans = INF;
set <ll> p;
int cmp[N];

void primes () {
    for (int i = 2; i*i < N; i++) if (!cmp[i])
        for (int j = i*i; j < N; j += i) cmp[j] = 1;
    for (int i = 2; i < N; i++) if (!cmp[i]) p.insert(i);
}

int main () {
    primes();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &t[i][j]);

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            int x = t[i][j];
            while (!p.count(x)) x++, cnt++;
        }
        ans = min(ans, cnt);
    }

    for (int j = 1; j <= m; j++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int x = t[i][j];
            while (!p.count(x)) x++, cnt++;
        }
        ans = min(ans, cnt);
    }

    printf("%d\n", ans);
    return 0;
}
