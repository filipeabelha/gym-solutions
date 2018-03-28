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
const int N = 2e3+5;

int a, l, h;

int main () {
    scanf("%d%d%d", &a, &l, &h);

    int c = (4*a-l)/2;

    for (int r = 0; r < N; r++) {
        for (int u = 0; u < N; u++) {
            if (c + r + u != a) continue;
            if (2*c + 4*r + 4*u != l) continue;
            if (2*r + u != h) continue;
            return printf("%d\n", u), 0;
        }
    }
    return 0;
}
