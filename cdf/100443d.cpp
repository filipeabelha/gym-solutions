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
const int N = 1e3+5;

string s[2][2];
vector <string> ans(N);

int t, n, cnt;
string k;

pair <int, char> ind (string k, int i) {
    string z = "";
    z.pb(k[i]);
    z.pb(k[i+1]);
    z.pb(k[i+2]);

    if (z == "LLR") return mp(0, 'L');
    if (z == "RLL") return mp(1, 'L');
    if (z == "LRR") return mp(0, 'R');
    if (z == "RRL") return mp(1, 'R');
    return mp(-1, 'A');
}

bool chk (string k) {
    int sz = k.size();
    if (sz <= 2) return 1;

    string r;
    bool ok;
    vi v;
    int j;

    r = "";
    ok = 1;
    v.clear();

    for (j = 0; j < sz-2; j += 2) {
        auto p = ind(k, j);
        if (p.st < 0) ok = 0;
        r += p.nd, v.pb(p.st);
    }
    if (j == (sz-2)) {
        if (k[j] == 'L' and k[j+1] == 'L') r += 'L', v.pb(0);
        if (k[j] == 'R' and k[j+1] == 'L') r += 'L', v.pb(1);
        if (k[j] == 'L' and k[j+1] == 'R') r += 'R', v.pb(0);
        if (k[j] == 'R' and k[j+1] == 'R') r += 'R', v.pb(1);
    } else if (j == (sz-1)) v.pb((k[j] == 'R'));

    for (int i = 1; i < v.size(); i++) if (v[i-1] == v[i]) ok = 0;
    if (ok and chk(r)) return 1;

    /******************/

    r = "";
    ok = 1;
    v.clear();

    if (k[0] == 'L' and k[1] == 'R') r += 'L', v.pb(0);
    if (k[0] == 'L' and k[1] == 'L') r += 'L', v.pb(1);
    if (k[0] == 'R' and k[1] == 'R') r += 'R', v.pb(0);
    if (k[0] == 'R' and k[1] == 'L') r += 'R', v.pb(1);

    for (j = 1; j < sz-2; j += 2) {
        auto p = ind(k, j);
        if (p.st < 0) ok = 0;
        r += p.nd, v.pb(p.st);
    }
    if (j == (sz-2)) {
        if (k[j] == 'L' and k[j+1] == 'L') r += 'L', v.pb(0);
        if (k[j] == 'R' and k[j+1] == 'L') r += 'L', v.pb(1);
        if (k[j] == 'L' and k[j+1] == 'R') r += 'R', v.pb(0);
        if (k[j] == 'R' and k[j+1] == 'R') r += 'R', v.pb(1);
    } else if (j == (sz-1)) v.pb((k[j] == 'R'));

    for (int i = 1; i < v.size(); i++) if (v[i-1] == v[i]) ok = 0;
    if (ok and chk(r)) return 1;

    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    s[0][0] = "LR";
    s[0][1] = "LL";
    s[1][0] = "RR";
    s[1][1] = "RL";

    ans[1] = "L";

    for (int i = 2; i <= 10; i++) {
        string k = "L";
        for (int j = 0; j < ans[i-1].size(); j++)
            k = k+s[ans[i-1][j] == 'R'][j&1];
        ans[i] = k;
    }

    cin >> t;
    while (t-- and ++cnt) {
        cin >> n >> k;
        printf("Case %d: ", cnt);
        if (n <= 10) {
            int a = 0;
            for (int i = 0; i+k.size()-1 < ans[n].size(); i++) {
                int b = 1;
                for (int j = 0; j < k.size(); j++) {
                    if (ans[n][i+j] != k[j]) b = 0;
                }
                if (b) a = 1;
            }
            printf("%s\n", a ? "Yes" : "No");
        } else printf("%s\n", chk(k) ? "Yes" : "No");
    }

    return 0;
}
