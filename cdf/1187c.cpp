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
const int INF = 1000000000, MOD = 1e9+7;
const int N = 1e5+5;

int n, m, t, l, r, a[N], err;
vector <pii> q1, q2;

int main () {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) a[i] = n-i+1;

    while (m--) {
        scanf("%d%d%d", &t, &l, &r);
        if (t == 0) q2.pb({l, r});
        else q1.pb({l, r});
    }

    sort(q1.begin(), q1.end());

    for (auto p : q1) {
        int l = p.st;
        int r = p.nd;
        for (int i = l+1; i <= r; i++) {
            a[i] = a[i-1];
        }
    }

    for (auto p : q2) {
        int l = p.st;
        int r = p.nd;
        int ok = 0;
        for (int i = l; i < r; i++) {
            if (a[i] > a[i+1])
                ok = 1;
        }
        if (!ok) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i==n]);
    return 0;
}
