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
string ans;

int main () {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if ((i+2 < s.size()) and s[i] != s[i+1] and s[i] != s[i+2] and s[i+1] != s[i+2]) {
            ans.pb('C');
            i += 2;
        } else if (s[i] == 'R') ans.pb('S');
        else if (s[i] == 'B') ans.pb('K');
        else if (s[i] == 'L') ans.pb('H');
    }
    cout << ans << endl;
    return 0;
}
