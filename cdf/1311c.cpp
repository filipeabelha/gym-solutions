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

int t;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;
        vi f(n+10);
        for (int i = 0; i < f.size(); i++) f[i] = 0;

        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            f[0]++;
            f[x]--;
        }
        f[0]++;
        f[n]--;
        for (int i = 1; i < f.size(); i++) f[i] += f[i-1];

        vi cnt(30, 0);
        for (int i = 0; i < s.size(); i++) {
            int c = s[i];
            cnt[c-'a'] += f[i];
        }

        for (int i = 0; i < 26; i++) printf("%d ", cnt[i]);
        printf("\n");
    }

    return 0;
}
