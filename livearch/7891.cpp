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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e2+10;

int ans[N];
int n, c, s, op;

int main () {
    while (~scanf("%d%d%d", &n, &c, &s)) {
        cl(ans, 0);
        int x = 1;
        ans[1] = 1;
        for (int i = 1; i <= c; i++) {
            scanf("%d", &op);
            x += op;
            if (x < 1) x += n;
            if (x > n) x -= n;
            ans[x]++;
        }
        printf("%d\n", ans[s]);
    }
    return 0;
}
