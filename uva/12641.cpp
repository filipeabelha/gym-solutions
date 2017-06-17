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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

int n, ok;
vector <string> u, v;
char foo[500], chr;

int main () {
    scanf("%d", &n);
    while (n--) {
        while (1) {
            scanf("%s%c", foo, &chr);
            u.pb(foo);
            if (chr == '\n') break;
        }
        while (1) {
            scanf("%s%c", foo, &chr);
            v.pb(foo);
            if (chr == '\n') break;
        }
        for (int i = 0; i < v.size(); i++) {
            string s = v[i];
            sort(s.begin(), s.end());
            for (int j = 0; j < u.size(); j++) {
                string bar = u[j];
                sort(bar.begin(), bar.end());
                if (u[j][0] != v[i][0]) continue;
                if (u[j][u[j].size()-1] != v[i][v[i].size()-1]) continue;
                if (s != bar) continue;
                if (ok) continue;
                ok = 1;
                printf("%s%s", u[j].c_str(), i < v.size()-1 ? " " : "\n");
            }
            if (!ok) printf("%s%s", v[i].c_str(), i < v.size()-1 ? " " : "\n");
            ok = 0;
        }
        u.clear(); v.clear();
    }
    return 0;
}
