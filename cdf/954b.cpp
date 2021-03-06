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

int n, ans, ok = 1;
string s;

int main () {
    cin >> n >> s;
    for (int i = n-1; i >= 0; i--) {
        if (ok and i&1 and s.substr(0, i/2+1) == s.substr(i/2+1, i/2+1)) {
            i /= 2;
            i++;
            ok = 0;
        }
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
