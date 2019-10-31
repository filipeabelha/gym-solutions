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
const int N = 2e5+5;

int n, m, f[30][N], g[30];
string s, t;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s >> m;
    for (int i = 1; i <= n; i++) {
        int c = s[i-1]-'a';
        f[c][i]++;
    }

    for (int i = 0; i < 30; i++)
        for (int j = 1; j < N; j++)
            f[i][j] += f[i][j-1];

    while (m--) {
        cin >> t;
        cl(g, 0);
        int ans = 0;
        for (auto c : t) g[c-'a']++;
        for (auto c : t) {
            c -= 'a';
            int z = lower_bound(f[c], f[c]+n, g[c]) - f[c];
            ans = max(ans, z);
        }
        printf("%d\n", ans);
    }
    return 0;
}
