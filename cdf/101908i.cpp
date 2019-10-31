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
const int N = 1e5+5;

int n, m, l, k, x, pos;
int turnedOn[N], cnt;
vi oper[N];

int main () {
    scanf("%d%d%d", &n, &m, &l);

    for (int i = 1; i <= l; i++) {
        scanf("%d", &pos);
        turnedOn[pos] = 1;
    }

    cnt = l;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            scanf("%d", &x);
            oper[i].pb(x);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto pos : oper[i]) {
            turnedOn[pos] ^= 1;
            if (turnedOn[pos]) cnt++;
            else cnt--;
        }
        if (cnt == 0) {
            printf("%d\n", i);
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto pos : oper[i]) {
            turnedOn[pos] ^= 1;
            if (turnedOn[pos]) cnt++;
            else cnt--;
        }
        if (cnt == 0) {
            printf("%d\n", n+i);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}
