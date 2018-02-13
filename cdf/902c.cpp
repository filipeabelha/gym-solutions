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
const int N = 2e5+5;

int h, x, v[N], amb;
int para[N], parb[N];

int main () {
    scanf("%d", &h);
    for (int i = 0; i <= h; i++) scanf("%d", &v[i]);
    for (int i = 1; i <= h; i++) if (v[i] > 1 and v[i-1] > 1) amb = 1;
    if (!amb) {
        printf("perfect\n");
        return 0;
    }
    printf("ambiguous\n");
    para[1] = parb[1] = 0;
    int pre = 1, cur = 1;
    for (int i = 1; i <= h; i++) {
        if (v[i-1] == 1) {
            for (int j = pre+1; j <= pre+v[i]; j++)
                para[j] = parb[j] = pre;
            pre += v[i];
            continue;
        }
        cur = pre+v[i];
        for (int j = pre+1; j <= pre+v[i]; j++) {
            para[j] = parb[j] = pre;
        }
        parb[cur] = pre-1;
        pre = cur;
    }
    for (int i = 1; i <= pre; i++) printf("%d ", para[i]); printf("\n");
    for (int i = 1; i <= pre; i++) printf("%d ", parb[i]); printf("\n");
    return 0;
}
