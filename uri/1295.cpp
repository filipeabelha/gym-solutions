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
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vii;

const int INF = 50000, MOD = 1e9+7, EPS = 1e-6, N = 1e5+10;

int n, cnt;
vector <pdd> v, strip;
double x, y, ans;

double solve (int l, int r) {
    double dis = INF;
    if (abs(l-r) <= 3) {
        for (int i = l; i <= r; i++) for (int j = i+1; j <= r; j++)
            dis = min(dis, hypot(abs(v[i].st-v[j].st), abs(v[i].nd-v[j].nd)));
        return dis;
    }
    int m = (l+r)/2;
    dis = min(solve(l, m), solve(m+1, r));
    strip.clear();
    for (int i = m; i >= l; i--) {
        if (abs(v[m].st-v[i].st) > dis) break;
        swap(v[i].st, v[i].nd);
        strip.pb(v[i]);
        swap(v[i].st, v[i].nd);
    }
    for (int i = m+1; i <= r; i++) {
        if (abs(v[m+1].st-v[i].st) > dis) break;
        swap(v[i].st, v[i].nd);
        strip.pb(v[i]);
        swap(v[i].st, v[i].nd);
    }
    sort(strip.begin(), strip.end());
    for (int i = 1; i < strip.size(); i++) {
        for (int j = i-1; j >= 0; j--) {
            if (strip[i].st-strip[j].st > dis) break;
            dis = min(dis, hypot(abs(strip[i].st-strip[j].st), abs(strip[i].nd-strip[j].nd)));
        }
    }
    return dis;
}

int main () {
    while (~scanf("%d", &n) and n) {
        ans = INF;
        v.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%lf%lf", &x, &y);
            v.pb(mp(x, y));
        }
        sort(v.begin(), v.end());
        if (n > 1) {
            ans = solve(0, n-1);
            if (ans < 10000) printf("%.4lf\n", ans);
            else printf("INFINITY\n");
        } else if (n == 1) printf("INFINITY\n");
        else printf("0.0000\n");
    }
    return 0;
}
