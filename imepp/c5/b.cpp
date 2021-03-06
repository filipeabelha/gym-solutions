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
const int N = 1e5+5;

int n, a, b, aa, bb;
set <ld> s;

int vert;

int main () {
    scanf("%d%d%d",&n,&a,&b);

    while (n--) {
        scanf("%d%d", &aa, &bb);

        int x = aa - a;
        int y = bb - b;

        if (x == 0) vert = 1;
        else {
            ld tg = (ld) y/x;
            s.insert(tg);
        }
    }

    printf("%d\n", (int) s.size() + vert);
    return 0;
}
