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
const int N = 5e3+5;

int t, n, d;
int par[N], dep[N], cnt[N], isBad[N];

int main () {
    scanf("%d", &t);
    while (t--) {
        cl(par, 0);
        cl(dep, 0);
        cl(cnt, 0);
        cl(isBad, 0);

        scanf("%d%d", &n, &d);

        int mn = 0;
        int k = n-1;
        for (int i = 1; ; i++) {
            if (k >= (1 << i)) {
                k -= (1 << i);
                mn += (1 << i)*i;
            } else {
                mn += k*i;
                break;
            }
        }

        int cur = n*(n-1)/2;

        if (d < mn or d > cur) {
            printf("NO\n");
            continue;
        }

        int ok = 1;

        for (int i = 2; i <= n; i++) {
            par[i] = dep[i] = i-1;
            cnt[par[i]]++;
        }

        while (d < cur) {
            int v = -1;
            for (int i = 1; i <= n; i++) {
                if (!isBad[i] and !cnt[i] and (v == -1 or dep[i] < dep[v])) {
                    v = i;
                }
            }
            if (v == -1) break;

            int p = -1;
            for (int i = 1; i <= n; i++) {
                if (dep[i] == dep[v]-2 and cnt[i] < 2) {
                    p = i;
                }
            }

            if (p == -1) {
                isBad[v] = 1;
                continue;
            }

            cur--;
            cnt[par[v]]--;
            cnt[p]++;
            dep[v]--;
            par[v] = p;
        }

        if (ok and d == cur) {
            printf("YES\n");
            for (int i = 2; i <= n; i++)
                printf("%d%c", par[i], " \n"[i==n]);
        } else printf("NO\n");

    }

    return 0;
}
