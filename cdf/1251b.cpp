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

int t;
map <char, int> f;
string s;
vi sz;
int odd, eve, n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        f.clear();
        sz.clear();
        odd = eve = n = 0;

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> s;
            for (auto c : s) f[c]++;
            sz.pb(-s.size());
        }

        for (auto p : f) {
            if (p.nd&1) odd++, eve += p.nd-1;
            else eve += p.nd;
        }

        sort(sz.begin(), sz.end());
        for (auto& x : sz) x = -x;
        int ans = 0;
        while (sz.size()) {
            if ((eve + (odd >= 1)) >= sz.back()) {
                if (sz.back()&1) {
                    if (odd) {
                        odd--;
                        sz.back()--;
                        eve -= sz.back();
                        sz.pop_back();
                    } else {
                        eve -= sz.back();
                        eve--;
                        odd++;
                        sz.pop_back();
                        assert((eve % 2 == 0));
                    }
                } else {
                    eve -= sz.back();
                    sz.pop_back();
                }
                ans++;
            } else break;
        }
        cout << ans << "\n";
    }

    return 0;
}
