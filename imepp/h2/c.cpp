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

map <pii, string> m;
map <pii, int> ok;
string s;
int x, y, t;

int main () {
    cin >> t;
    while (t--) {
        cin >> x >> y >> s;
        m[mp(x, y)] = s;
        ok[mp(x, y)] = 1;
    }
    cin >> t;
    while (t--) {
        cin >> x >> y;
        assert(ok[mp(x, y)]);
        printf("%s\n", m[mp(x, y)].c_str());
    }
    return 0;
}
