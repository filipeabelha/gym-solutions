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

int n, k, dp[N], a[N];

int mex (vi &states) {
    if (states.empty()) return 0;
    if (states[0] != 0) return 0;
    for (int i = 1; i < states.size(); i++) {
        if (states[i]-1 > states[i-1]) return states[i-1]+1;
    }
    return states.back()+1;
}

int main () {
    scanf("%d%d", &n, &k);
    cl(dp, 63);
    dp[0] = 0;

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < N; i++) {
        vi states;
        for (int j = 0; j < n; j++) {
            if (i-a[j] >= 0) states.pb(dp[i-a[j]]);
        }
        sort(states.begin(), states.end());
        dp[i] = mex(states);
    }

    printf("%s\n", dp[k] ? "First" : "Second");

    return 0;
}
