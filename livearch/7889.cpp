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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const ld PI = acos(-1.0);

int n;
long double ans;
vi a;

int main () {
    while (~scanf("%d", &n)) {
        for (int j, i=0; i < n; i++) scanf("%d", &j), a.pb(j);
        sort(a.begin(), a.end()); ans = 0;
        for (int i = 2; i < n; i += 2) ans += a[i-2]*a[i];
        for (int i = 1; i < n; i += 2) ans += a[i-2]*a[i];
        ans += a[0]*a[1];
        ans += a[n-1]*a[n-2];
        printf("%.3Lf\n", ans*0.5*sin(2*PI/n));
        a.clear();
    }
    return 0;
}
