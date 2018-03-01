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
const int N = 2e5+5;

int n, cnt, ok[N];
string s, t;
ld ans[N], x;
map <string, int> m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    m["pink"] = ++cnt; ok[cnt] = 1;
    m["blue"] = ++cnt;

    while (n--) {
        cin >> s >> t >> x;
        if (!m.count(s)) m[s] = ++cnt;
        if (!m.count(t)) m[t] = ++cnt;

        int i = m[s];
        int j = m[t];

        if (ok[j]) {
            if (ok[i]) ans[i] = max(ans[i], ans[j] + log(x));
            else       ans[i] = ans[j] + log(x);
            ok[i] = 1;
        }
    }

    printf("%.10Lf\n", !ok[2] ? 0 : (ans[2] > log(10)) ? 10 : exp(ans[2]));

    return 0;
}
