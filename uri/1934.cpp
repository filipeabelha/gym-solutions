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
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vii;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e3+10;

int x, y, l, k, cnt;
ll sys[N][N];
vector <vs> m;
char s[10], chr;
map <string, int> id;
map <int, string> idrev;
vs ans;

int main () {
    scanf("%d %d%c", &x, &y, &chr);
    l = x+y;

    // Scanning horizontal equations,
    // matrix B of Ax=B is stored in j = 0.
    // Equations stored in line 1 to x and
    // coefficients stored in columns 1 to cnt.
    for (int i = 1; i <= x; i++) {
        vs v;
        for (int j = 1; j <= y; j++) {
            scanf("%s%c", s, &chr);
            if (!id.count(s)) id[s] = ++cnt, idrev[id[s]] = s;
            sys[i][id[s]]++;
            v.pb(s);
        }
        m.pb(v);
        scanf("%d%c", &k, &chr);
        sys[i][0] = k;
    }

    // Scanning vertical equations
    for (int j = x; j < l; j++) {
        scanf("%d%c", &k, &chr);
        sys[j+1][0] = k;
        for (int i = 0; i < x; i++) {
            int ind = id[m[i][j-x]];
            sys[j+1][ind]++;
        }
    }

    while (ans.size() < cnt) {
        for (int i = 1; i <= l; i++) {
            int nonzeros = 0;
            int ind = 0;
            for (int j = 1; j <= cnt; j++)
                if (sys[i][j] != 0)
                    nonzeros++, ind = j;
            if (nonzeros == 1) {
                char solution[50];
                ll val = sys[i][0]/sys[i][ind];
                sprintf(solution, "%s %lld\n", idrev[ind].c_str(), val);
                ans.pb(solution);
                for (int ii = 1; ii <= l; ii++) {
                    sys[ii][0] -= val*sys[ii][ind];
                    sys[ii][ind] = 0;
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (auto x : ans) printf("%s", x.c_str());

    return 0;
}
