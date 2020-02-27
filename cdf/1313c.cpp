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
const int N = 5e5+5;

ll n, a[N], l[N], r[N], mx, imx;

int main () {
    scanf("%lld", &n);

    stack <ll> s;

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);

        while (s.size() and a[s.top()] >= a[i]) s.pop();
        if (s.empty()) l[i] = i*a[i];
        else {
            ll j = s.top();
            l[i] = l[j] + (i-j)*a[i];
        }
        s.push(i);
    }

    while (s.size()) s.pop();

    for (int i = n; i >= 1; i--) {
        while (s.size() and a[s.top()] >= a[i]) s.pop();
        if (s.empty()) r[i] = (n-i+1)*a[i];
        else {
            ll j = s.top();
            r[i] = r[j] + (j-i)*a[i];
        }
        s.push(i);

        if (mx < l[i]+r[i]-a[i]) {
            mx = l[i]+r[i]-a[i];
            imx = i;
        }
    }

    for (int i = imx-1; i >= 1; i--) a[i] = min(a[i], a[i+1]);
    for (int i = imx+1; i <= n; i++) a[i] = min(a[i], a[i-1]);

    for (int i = 1; i <= n; i++)
        printf("%lld%c", a[i], " \n"[i==n]);

    return 0;
}
