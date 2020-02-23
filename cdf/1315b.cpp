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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll a, b, p;
        string s;
        cin >> a >> b >> p >> s;

        vector <pll> v;
        if (s[0] == 'A') v.pb({1, a});
        else v.pb({1, b});

        for (int i = 1; i < s.size()-1; i++) {
            if (s[i] != s[i-1]) {
                if (s[i] == 'A') v.pb({i+1, a});
                else v.pb({i+1, b});
            }
        }

        reverse(v.begin(), v.end());

        int ok = 0;
        ll acc = 0;
        for (int i = 0; i < v.size(); i++) {
            acc += v[i].nd;
            if (acc > p) {
                if (i == 0) cout << s.size() << "\n";
                else cout << v[i-1].st << "\n";
                ok = 1;
                break;
            }
        }

        if (!ok) cout << "1\n";

    }

    return 0;
}
