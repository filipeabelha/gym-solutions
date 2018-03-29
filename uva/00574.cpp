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

int n, k, a[N];
bool f[N];
set <vi, greater <vi> > ans;

void bk (int i, int s) {
    if (i >= k) return;
    if (s > n) return;
    f[i] = true;
    s += a[i];
    if (s == n) {
        vi v;
        for (int i = 0; i < k; i++) if (f[k-1-i]) v.pb(a[k-1-i]);
        ans.insert(v);
        f[i] = false;
        return;
    }
    for (int j = i+1; j < k; j++) bk(j, s);
    f[i] = false;
}

int main () {
    while (~scanf("%d%d", &n, &k) and n and k) {
        ans.clear();
        printf("Sums of %d:\n", n);
        for (int i = 0; i < k; i++) scanf("%d", &a[k-1-i]);
        for (int i = 0; i < k; i++) bk(i, 0);
        if (ans.empty()) printf("NONE\n");
        for (auto v : ans) {
            printf("%d", v[0]);
            for (int i = 1; i < v.size(); i++)
                printf("+%d", v[i]);
            printf("\n");
        }
    }
    return 0;
}
