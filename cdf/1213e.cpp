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
string s, t;
set <string> u;

int main () {
    cin >> n >> s >> t;

    string k = "";
    for (int i = 1; i <= n; i++) k += "abc";
    u.insert(k);

    k = "";
    for (int i = 1; i <= n; i++) k += "acb";
    u.insert(k);

    k = "";
    for (int i = 1; i <= n; i++) k += "bac";
    u.insert(k);

    k = "";
    for (int i = 1; i <= n; i++) k += "bca";
    u.insert(k);

    k = "";
    for (int i = 1; i <= n; i++) k += "cab";
    u.insert(k);

    k = "";
    for (int i = 1; i <= n; i++) k += "cba";
    u.insert(k);

    k = "";
    for (int i = 1; i <= n; i++) k += "ab";
    for (int i = 1; i <= n; i++) k += "c";
    u.insert(k);
    reverse(k.begin(), k.end());
    u.insert(k);

    k = "";
    for (int i = 1; i <= n; i++) k += "ba";
    for (int i = 1; i <= n; i++) k += "c";
    u.insert(k);
    reverse(k.begin(), k.end());
    u.insert(k);

    k = "";
    for (int i = 1; i <= n; i++) k += "ac";
    for (int i = 1; i <= n; i++) k += "b";
    u.insert(k);
    reverse(k.begin(), k.end());
    u.insert(k);

    k = "";
    for (int i = 1; i <= n; i++) k += "ca";
    for (int i = 1; i <= n; i++) k += "b";
    u.insert(k);
    reverse(k.begin(), k.end());
    u.insert(k);

    k = "";
    for (int i = 1; i <= n; i++) k += "bc";
    for (int i = 1; i <= n; i++) k += "a";
    u.insert(k);
    reverse(k.begin(), k.end());
    u.insert(k);

    k = "";
    for (int i = 1; i <= n; i++) k += "cb";
    for (int i = 1; i <= n; i++) k += "a";
    u.insert(k);
    reverse(k.begin(), k.end());
    u.insert(k);

    cout << "YES\n";

    for (auto k : u) {
        int ok = 1;
        for (int i = 1; i < k.size(); i++) {
            if (s[0] == k[i-1] and s[1] == k[i]) ok = 0;
            if (t[0] == k[i-1] and t[1] == k[i]) ok = 0;
        }

        if (ok) {
            cout << k << "\n";
            return 0;
        }
    }

    return 0;
}
