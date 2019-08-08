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

int n, g = -1, x, cnt = 60;

int main () {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int l = 0, m, r = 1000000000;
    while (l < r) {
        m = (l+r)/2;
        cout << "> " << m << endl;
        fflush(stdout);
        cnt--;
        cin >> x;
        assert(x != -1);
        if (x == 1) l = m+1;
        else r = m;
    }
    m = (l+r)/2;

    while (cnt--) {
        int i = (1LL * rand() * rand()) % n + 1;
        cout << "? " << i << endl;
        cin >> x;
        assert(x != -1);
        if (x == m) continue;
        if (g == -1) g = m-x;
        else g = gcd(g, m-x);
    }
    cout << "! " << m-(n-1)*g << " " << g << endl;
    return 0;

