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

int w, b;
ld memo[N][N][2];

ld dp (int w, int b, int k) {
    if (memo[w][b][k] != -1) return memo[w][b][k];

    if (w < 0 or b < 0) return memo[w][b][k] = 0;

    if (k == 0) {
        if (w == 0) return memo[w][b][0] = 0;
        if (b == 0) return memo[w][b][0] = 1;
        ld p = (ld) w/(w+b);
        return memo[w][b][0] = p + (1.-p)*dp(w, b-1, 1);
    }

    if (k == 1) {
        if (w == 0) return memo[w][b][1] = 0;
        if (b == 0) return memo[w][b][1] = 0;
        ld p = (ld) w/(w+b);
        return memo[w][b][1] = (1.-p)*(((ld) w/(w+b-1))*dp(w-1, b-1, 0) + ((ld)(b-1)/(w+b-1))*dp(w, b-2, 0));
    }
}

int main () {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < 2; k++)
                memo[i][j][k] = -1;

    scanf("%d%d", &w, &b);
    printf("%.10Lf\n", dp(w, b, 0));

    return 0;
}
