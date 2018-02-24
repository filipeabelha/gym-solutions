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
const int INF = 1e9, MOD = 1e9+7;
const int N = 1e5+5;

int n, a[N], b[N], l = -INF, r = INF;
char c;

set <int> lL, gL, lR, gR;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf(" %d ", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%c", &c), b[i] = c - '0';
    for (int i = 5; i <= n; i++) {
        if (b[i-1] != b[i-2] or b[i-1] != b[i-3] or b[i-1] != b[i-4]) continue;
        if (b[i] == 0 and b[i-1] == 1) {
            gR.insert(a[i]);
            gR.insert(a[i-1]);
            gR.insert(a[i-2]);
            gR.insert(a[i-3]);
            gR.insert(a[i-4]);
        } else if (b[i] == 1 and b[i-1] == 0) {
            lL.insert(a[i]);
            lL.insert(a[i-1]);
            lL.insert(a[i-2]);
            lL.insert(a[i-3]);
            lL.insert(a[i-4]);
        } else if (b[i] == 0) {
            lR.insert(a[i]);
            lR.insert(a[i-1]);
            lR.insert(a[i-2]);
            lR.insert(a[i-3]);
            lR.insert(a[i-4]);
        } else if (b[i] == 1) {
            gL.insert(a[i]);
            gL.insert(a[i-1]);
            gL.insert(a[i-2]);
            gL.insert(a[i-3]);
            gL.insert(a[i-4]);
        }
    }
    for (auto z : lL) l = max(l, z); l++;
    for (auto z : gR) r = min(r, z); r--;
    printf("%d %d\n", l, r);
    return 0;
}
