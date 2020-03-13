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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

int n, m, x, ans, mylcm = 1, a[N], cnt[N], v[N];

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] <= m) cnt[a[i]]++;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j += i) {
            v[j] += cnt[i];
            if (ans < v[j]) {
                ans = v[j];
                mylcm = j;
            }
        }
    }

    printf("%d %d\n", mylcm, ans);

    for (int i = 1; i <= n; i++) {
        if (mylcm >= a[i] and mylcm % a[i] == 0) {
            printf("%d ", i);
        }
    }
    if (ans) printf("\n");

    return 0;
}
