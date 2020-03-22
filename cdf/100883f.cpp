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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

set <string> ans;
string s, t, q;
vi v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        v.clear();
        ans.clear();

        cin >> s >> t;
        for (auto c : s) v.pb(1);
        for (auto c : t) v.pb(2);

        do {
            int i = 0;
            int j = 0;
            q.clear();
            for (auto e : v) {
                if (e == 1) q += s[i++];
                else        q += t[j++];
            }
            ans.insert(q);
        } while (next_permutation(v.begin(), v.end()));

        for (auto s : ans) cout << s << "\n";
        cout << "\n";
    }

    return 0;
}
