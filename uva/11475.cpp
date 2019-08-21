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

string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (getline(cin, s)) {
        string t = s;
        reverse(t.begin(), t.end());
        string q = t + '$' + s;
        int n = s.size();
        vi v = z(q);

        int ans = 0;
        for (int i = n; i < v.size(); i++) {
            if (i + v[i] == v.size()) {
                ans = v[i];
                break;
            }
        }

        if (ans) {
            int ind = s.size()-ans-1;
            for (int i = ind; i >= 0; i--) s += s[i];
        }
        cout << s << endl;
    }

    return 0;
}
