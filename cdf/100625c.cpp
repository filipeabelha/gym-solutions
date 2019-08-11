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

int tc, n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tc;
    while (tc--) {
        cin >> n;
        vector <string> v(n), vde;
        string s, t;

        for (int i = 0; i < n; i++) cin >> v[i];
        cin >> s >> t;

        for (int i = 0; i < n; i++) {
            string en = "00000000000000000000000000";
            string de = "00000000000000000000000000";
            int ok = 1;
            for (int j = 0; j < s.size(); j++) {
                if (en[s[j]-'a'] == '0' and de[v[i][j]-'a'] == '0') {
                    en[s[j]-'a'] = v[i][j];
                    de[v[i][j]-'a'] = s[j];
                }
                else if (en[s[j]-'a'] != v[i][j] or
                         de[v[i][j]-'a'] != s[j]) ok = 0;
            }

            if (v[i].size() != s.size()) ok = 0;

            if (ok) vde.pb(de);
        }

        if (vde.size()) {
            string de = vde[0];
            for (int j = 1; j < vde.size(); j++) {
                string p = vde[j];
                string q = vde[j-1];

                for (int i = 0; i < 26; i++) {
                    if (p[i] == '0' or p[i] != q[i]) de[i] = '?';
                    else if (de[i] == '0') de[i] = p[i];
                }
            }
            set <char> g;
            for (int i = 0; i < 26; i++) g.insert(i+'a');

            for (auto& elem : de) {
                if (elem == '0') elem = '?';
                g.erase(elem);
            }

            if (g.size() == 1)
                for (auto& elem : de)
                    if (elem == '?')
                        elem = *g.begin();

            for (int i = 0; i < t.size(); i++) {
                t[i] = de[t[i]-'a'];
            }

            cout << t << endl;
        } else cout << "IMPOSSIBLE" << endl;

    }
    return 0;
}
