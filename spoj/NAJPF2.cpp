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
const int INF = 0x3f3f3f3f;
const int N = 1e5+5;

string s, p, q;

vi z (string q) {
    vi z(q.size());
    for (int i = 1, l = 0, r = 0, n = q.size(); i < n; i++) {
        if (i <= r) z[i] = min(z[i-l], r-i+1);
        while (i + z[i] < n and q[z[i]] == q[z[i] + i]) z[i]++;
        if (i+z[i]-1 > r) {
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}

int t;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> s >> p;
        q = p + '$' + s;

        vi ans;

        vi v = z(q);
        for (int i = p.size(); i < q.size(); i++) {
            if (v[i] == p.size()) {
                ans.pb(i-p.size());
            }
        }

        if (ans.size()) {
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " \n"[i+1==ans.size()];
        } else cout << "Not Found" << endl;

        if (t) cout << endl;
    }

    return 0;
}
