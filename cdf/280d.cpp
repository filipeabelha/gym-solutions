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

int n, m, k, ok, c = 1, cnt[N];
pii w[N], y[N];

int main () {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n+m; i++) scanf("%d", &w[i].st), w[i].nd = i, y[i] = w[i];

    sort(w, w+n+m);
    sort(y, y+n+m);

    w[0].st = c;
    swap(w[0].st, w[0].nd);

    for (int i = 1; i < n+m; i++) {
        if (y[i].st != y[i-1].st) w[i].st = ++c;
        else w[i].st = c;
        swap(w[i].st, w[i].nd);
    }

    sort(w, w+n+m);

    for (int i = 0; i < n; i++)   cnt[w[i].nd]++;
    for (int i = n; i < n+m; i++) cnt[w[i].nd]--;

    ll sum = 0;
    for (int i = c; i >= 1; i--) {
        sum += cnt[i];
        if (sum > 0) ok = 1;
    }

    printf("%s\n", ok ? "YES" : "NO");

    return 0;
}
