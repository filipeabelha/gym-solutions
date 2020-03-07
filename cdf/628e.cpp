#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e3+5;

int n, m, t[N][N], l[N][N], r[N][N], d[N][N];
char c;
ll ans;

int bit[2*N];
vi rm[N];

void add (int p, int v) {
    p += N;
    for (p+=2; p<2*N; p += p&-p) bit[p] += v;
}

int query (int p) {
    p += N;
    int r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

int rangesum (int a, int b) {
    return query(b)-query(a-1);
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &c);
            t[i][j] = (c == 'z');
            ans += t[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (t[i][j] and t[i][j-1]) l[i][j] = 1 + l[i][j-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (t[i][j] and t[i][j+1]) r[i][j] = 1 + r[i][j+1];
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            if (t[i][j] and t[i+1][j-1]) d[i][j] = 1 + d[i+1][j-1];
        }
    }

    for (int di = 1; di <= n; di++) {
        cl(bit, 0);
        for (int i = 0; i < N; i++) rm[i].clear();

        for (int k = min(di-1, m-1); k >= 0; k--) {
            int i = di-k;
            int j = k+1;

            int c = min(l[i][j], d[i][j]);
            rm[i+c+1].pb(i);
            while (rm[i].size()) {
                add(rm[i].back(), -1);
                rm[i].pop_back();
            }

            ans += rangesum(i-r[i][j], i);
            add(i, 1);
        }
    }

    for (int di = 2; di <= m; di++) {
        cl(bit, 0);
        for (int i = 0; i < N; i++) rm[i].clear();

        for (int k = min(m-di, n-1); k >= 0; k--) {
            int i = n-k;
            int j = di+k;

            int c = min(l[i][j], d[i][j]);
            rm[i+c+1].pb(i);
            while (rm[i].size()) {
                add(rm[i].back(), -1);
                rm[i].pop_back();
            }

            ans += rangesum(i-r[i][j], i);
            add(i, 1);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
