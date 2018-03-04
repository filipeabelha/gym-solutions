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

ll f[10], n, ans;
set <string> u;
set <vi> w;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> s;
        if (u.count(s)) continue;
        u.insert(s);

        if (s[0] == 'M') f[0]++;
        if (s[0] == 'A') f[1]++;
        if (s[0] == 'R') f[2]++;
        if (s[0] == 'C') f[3]++;
        if (s[0] == 'H') f[4]++;
    }
    vi k;
    for (int i = 0; i < 5; i++) k.pb(i);

    do {
        vi z = k;
        sort(z.begin(), z.begin()+3);
        z.pop_back();
        z.pop_back();
        if (w.count(z)) continue;
        w.insert(z);
        ans += f[z[0]]*f[z[1]]*f[z[2]];
    } while (next_permutation(k.begin(), k.end()));

    cout << ans << endl;
    return 0;
}
