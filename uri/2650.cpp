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
const int N = 1e2+5;

int n, h, x, cnt;
char a[N][N];

int main () {
    scanf("%d%d ", &n, &h);
    while (n--) {
        cnt = 0;
        while (++cnt) {
            scanf("%s", a[cnt]);
            if (a[cnt][0] >= '0' and a[cnt][0] <= '9') break;
        }
        sscanf(a[cnt], "%d ", &x);
        if (x > h) for (int i = 1; i < cnt; i++) printf("%s%s", a[i], i < cnt-1 ? " " : "\n");
    }
    return 0;
}
