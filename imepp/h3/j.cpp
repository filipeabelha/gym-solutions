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

int cnt, t[10][10], a, b, n;

bool chk (int l, int c) {
    for (int i = 1; i <= 8; i++) for (int j = 1; j <= 8; j++) {
        if (((i-j) == (l-c)) or ((i+j) == (l+c)) or i == l or j == c)
            if (t[i][j]) return false;
    }
    return true;
}

void slv (int c) {
    if (c == b) {
        slv(c+1);
        return;
    }
    if (c == 9) {
        cnt++;
        printf("%2d      ", cnt);
        int fst = 0;
        for (int col = 1; col <= 8; col++) for (int lin = 1; lin <= 8; lin++)
            if (t[lin][col]) printf("%s%d", fst ? " " : "", lin), fst = 1;
        printf("\n");
        return;
    }
    for (int i = 1; i <= 8; i++) {
        if (!chk(i, c)) continue;

        t[i][c] = 1;
        slv(c+1);
        t[i][c] = 0;
    }
}

int main () {
    scanf("%d", &n);
    while (n--) {
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        cl(t, 0);
        cnt = 0;
        scanf("%d%d", &a, &b);
        t[a][b] = 1;
        slv(1);
        if (n) printf("\n");
    }
    return 0;
}
