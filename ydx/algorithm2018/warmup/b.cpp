#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

string s;
string ans = "zzzzzz";

int main () {
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) {
            string z = "";
            z.pb(s[i]); z.pb(s[i]);
            if (z < ans) ans = z;
        }
    }
    if (ans.size() < 6) {
        printf("%s\n", ans.c_str());
        return 0;
    }
    for (int i = 2; i < s.size(); i++) {
        if (s[i] == s[i-2]) {
            string z = "";
            z.pb(s[i]); z.pb(s[i-1]); z.pb(s[i]);
            if (z < ans) ans = z;
        }
    }
    if (ans.size() < 6) {
        printf("%s\n", ans.c_str());
        return 0;
    }
    printf("-1\n");
    return 0;
}
