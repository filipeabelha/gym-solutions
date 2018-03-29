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
const int N = 1e2+5;

int t[N][N];
vii sol;

bool chk (int i, int j) {
    for (int a = 1; a <= 8; a++)
        for (int b = 1; b <= 8; b++) {
            if (a == i and b == j) continue;
            if (t[i][b]) return false;
            if (t[a][j]) return false;
            if (a+b == i+j and t[a][b]) return false;
            if (a-b == i-j and t[a][b]) return false;
        }
    return true;
}

void getsol () {
    vi v;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            if (t[i][j]) v.pb(j);
    sol.pb(v);
}

void bk (int i) {
    if (i == 9) {
        getsol();
        return;
    }
    for (int j = 1; j <= 8; j++) {
        if (!chk(i, j)) continue;
        t[i][j] = 1;
        bk(i+1);
        t[i][j] = 0;
    }
}

int a[N], cnt;

int main () {
    bk(1);
    while (~scanf("%d", &a[0]) and ++cnt) {
        for (int i = 1; i < 8; i++) scanf("%d", &a[i]);

        int ans = INF;
        for (auto v : sol) {
            int s = 0;
            for (int i = 0; i < v.size(); i++) s += (v[i] != a[i]);
            ans = min(ans, s);
        }
        printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}
