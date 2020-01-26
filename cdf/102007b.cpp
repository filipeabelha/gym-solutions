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
const int N = 1e5+5;

int days (int m, int d) {
    int ans = 0;
    for (int i = 1; i < m; i++) {
        if (i == 1)  ans += 31;
        if (i == 2)  ans += 28;
        if (i == 3)  ans += 31;
        if (i == 4)  ans += 30;
        if (i == 5)  ans += 31;
        if (i == 6)  ans += 30;
        if (i == 7)  ans += 31;
        if (i == 8)  ans += 31;
        if (i == 9)  ans += 30;
        if (i == 10) ans += 31;
        if (i == 11) ans += 30;
    }
    return ans+d;
}

int diff (pii a, pii b) {
    int ans = days(a.st, a.nd) - days(b.st, b.nd);
    if (ans < 0) ans += 365;
    return ans;
}

int n, a, b, mx, ok[50][50];
vector <pii> v;
vector <piii> u;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %*s %d-%d", &a, &b);
        ok[a][b] = 1;
        v.pb({a, b});
    }
    for (int m = 1; m <= 12; m++) {
        for (int d = 1; d <= 31; d++) {
            if (m == 2 and d > 28) break;
            if (m == 4 and d > 30) break;
            if (m == 6 and d > 30) break;
            if (m == 9 and d > 30) break;
            if (m == 11 and d > 30) break;
            int dif = INF;
            pii q = {m, d};
            for (auto p : v) {
                dif = min(dif, diff(q, p));
            }
            if (mx == dif) {
                u.pb({diff(q, {10, 28}), q});
            }
            if (mx < dif) {
                mx = dif;
                u.clear();
                u.pb({diff(q, {10, 28}), q});
            }
        }
    }

    sort(u.begin(), u.end());

    printf("%02d-%02d\n", u[0].nd.st, u[0].nd.nd);

    return 0;
}
