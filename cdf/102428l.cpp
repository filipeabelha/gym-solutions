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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int x, y, a[N][N];
char c;

bool ok (int k) {
    for (int i = k; i <= x; i++)
        for (int j = k; j <= y; j++) {
            int cnt = a[i][j] - a[i][j-k+1] - a[i-k][j] + a[i-k][j-k+1];
            if (cnt == 0) return true;
        }
    return false;
}

int main () {
    scanf("%d%d", &x, &y);

    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++) {
            scanf(" %c", &c);
            a[i][j] = (c == 'G');
        }

    for (int i = 1; i <= x; i++) {
        for (int j = y; j >= 2; j--)
            a[i][j] = (a[i][j] != a[i][j-1]);
        a[i][1] = 0;
    }

    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
            a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];


    int l = 1, m, r = max(x, y);

    while (l < r) {
        m = (l+r+1)/2;

        if (!ok(m)) r = m-1;
        else        l = m;
    }

    printf("%d\n", ok(l) ? l*l : -1);

    return 0;
}
