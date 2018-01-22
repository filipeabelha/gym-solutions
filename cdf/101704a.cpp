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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LMOD = 1011112131415161719ll;
const int N = 1e5+5;

long double ans;
int x[N], y[N], n;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= n-1; i++) ans += x[i]*y[i+1];
    ans += x[n]*y[1];
    for (int i = 1; i <= n-1; i++) ans -= y[i]*x[i+1];
    ans -= y[n]*x[1];
    ans = abs(ans)/2;
    printf("%.3Lf\n", ans);
    return 0;
}
