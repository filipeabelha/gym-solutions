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

int n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> s;
        char c = s.back();
        s.pop_back();
        if      (c == 'a') s += "as";
        else if (c == 'i') s += "ios";
        else if (c == 'y') s += "ios";
        else if (c == 'l') s += "les";
        else if (c == 'n') s += "anes";
        else if (c == 'e' and s.back() == 'n') s.pop_back(), s += "anes";
        else if (c == 'o') s += "os";
        else if (c == 'r') s += "res";
        else if (c == 't') s += "tas";
        else if (c == 'u') s += "us";
        else if (c == 'v') s += "ves";
        else if (c == 'w') s += "was";
        else               s += c, s += "us";
        cout << s << endl;
    }

    return 0;
}
