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

int n;
vector <string> a;
map <string, int> f;
string s, t;

int main () {
    cin >> n;
    while (n--) {
        cin >> s >> t;
        if (s == "SCH" or a.size() == 10) continue;
        if ((f[s] < 2) or (s == "MSU" and f[s] < 4)) {
            a.pb(s + ' ' + t);
            f[s]++;
        }
    }
    printf("%d\n", (int) a.size());
    for (auto z : a) cout << z << endl;
    return 0;
}
