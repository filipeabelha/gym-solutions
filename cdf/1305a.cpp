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
const int N = 1e2+5;

int a[N], b[N];

int main () {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
        sort(a+1, a+1+n);
        sort(b+1, b+1+n);
        for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i==n]);
        for (int i = 1; i <= n; i++) printf("%d%c", b[i], " \n"[i==n]);
    }

    return 0;
}
