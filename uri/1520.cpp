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

int n, a, b, tgt;
vi v;

int main () {
    while (~scanf("%d", &n)) {
        v.clear();
        while (n--) {
            scanf("%d%d", &a, &b);
            for (int i = a; i <= b; i++) v.pb(i);
        }
        sort(v.begin(), v.end());
        int x, y;
        x = y = -1;
        scanf("%d", &tgt);
        for (int i = 0; i < v.size(); i++) if (v[i] == tgt) {
            y = i;
            if (x == -1) x = i;
        }
        printf("%d ", tgt);
        (x == -1 ? printf("not found\n") : printf("found from %d to %d\n", x, y));
    }
    return 0;
}
