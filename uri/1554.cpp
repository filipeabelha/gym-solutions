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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int tc, n;
int x, y;
int a, b;
int ans, disans;

int dis() {return abs(x-a)*abs(x-a)+abs(y-b)*abs(y-b);};

int main () {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d%d", &n, &x, &y);
        disans = 123456789; ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &a, &b);
            if (dis() < disans) disans = dis(), ans = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}
