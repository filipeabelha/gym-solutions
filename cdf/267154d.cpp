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

const ld eps = 1e-9, pi = acos(-1.);
const ll linf = 0x3f3f3f3f3f3f3f3f, lmod = 1011112131415161719ll;
const int inf = 0x3f3f3f3f, mod = 1e9+7;
const int n = 1e5+5;

string s, t;
vector <pii> ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    t = s;

    sort(t.begin(), t.end());

    for (int i = 0; i < s.size(); i++) if (s[i] != t[i]) {
        for (int j = i+1; j < s.size(); j++) if (s[i] == t[j]) {
            if (t[j] > t[i]) ans.pb({j+1, i+1});
            else             ans.pb({i+1, j+1});
            swap(t[j], t[i]);
            break;
        }
    }

    for (auto p : ans) printf("%d %d\n", p.st, p.nd);

    return 0;
}
