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

set <string> v;
map <string, bool> ok;
string s;

bool isPalindrome (string s) {
    int n = s.size();
    for (int i = 0; i < n; i++)
        if (s[i] != s[n-i-1]) return false;
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    while (n--) {
        cin >> s;
        v.insert(s);
    }

    string ans = "";
    string mx = "";

    for (auto s : v) {
        string t = s;
        reverse(t.begin(), t.end());
        if (t != s and v.count(t) and !ok[t]) {
            ans += s;
            ok[s] = ok[t] = true;
        }
        else if (isPalindrome(t) and t.size() > mx.size()) mx = t;
    }

    string rans = ans;
    reverse(rans.begin(), rans.end());

    ans = ans + mx + rans;

    cout << ans.size() << "\n";
    cout << ans << "\n";



    return 0;
}
