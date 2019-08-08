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

string s, ans;

int main () {
    cin >> s;
    int i = 0, j = s.size()-1;

    while (j-i >= 3) {
        if (s[i] == s[j]) {
            ans.pb(s[i]);
            i++;
            j--;
        } else if (s[i] == s[j-1]) {
            ans.pb(s[i]);
            i++;
            j -= 2;
        } else if (s[i+1] == s[j]) {
            ans.pb(s[i+1]);
            i += 2;
            j--;
        } else {
            ans.pb(s[i+1]);
            i += 2;
            j -= 2;
        }
    }

    string ansr = ans;
    reverse(ansr.begin(), ansr.end());

    if (j >= i) ans = ans + s[i] + ansr;
    else ans = ans + ansr;

    cout << ans << endl;

    return 0;
}
