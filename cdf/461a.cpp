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
const int N = 3e5+5;

int n;
ll v[N], sum, ans;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
        sum += v[i];
    }
    sort(v, v+n);
    ans = sum;
    for (int i = 0; i < n; i++) {
        ans += sum;
        sum -= v[i];
    }
    ans -= v[n-1];
    printf("%lld\n", ans);
    return 0;
}
