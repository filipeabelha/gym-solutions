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
#define gcd(x, y) __gcd((x), (y))

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
const int N = 1e5+5;

bool chk (int a, int b, int c) {
    if (a >= b+c) return false;
    if (b >= a+c) return false;
    if (c >= a+b) return false;
    return true;
}

vi v;
int n, x;

int main () {
    scanf("%d", &n);
    while (n--) scanf("%d", &x), v.pb(x);
    sort(v.begin(), v.end());
    for (int i = 2; i < v.size(); i++) {
        if (chk(v[i-2], v[i-1], v[i])) return printf("YES\n"), 0;
    }
    printf("NO\n");
    return 0;
}
