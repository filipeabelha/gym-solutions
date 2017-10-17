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
typedef pair < pair <ld, ld>, string> T;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, y, yy, z, zz;
char ss[N];
vector <T> v;
pair <ld, vector <string> > ans;

int main () {
    ans.st = 1000;
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %s %d.%d %d.%d ", ss, &y, &yy, &z, &zz);
        v.pb(mp(mp(z+zz/100.0, y+yy/100.0), ss));
        sort(v.begin(), v.end());
    }
    for (int i = 0; i < n; i++) {
        vector <T> vv = v;
        vv.erase(vv.begin()+i, vv.begin()+i+1);

        vector <string> team;
        team.pb(v[i].nd);
        team.pb(vv[0].nd);
        team.pb(vv[1].nd);
        team.pb(vv[2].nd);

        ld t = v[i].st.nd + vv[0].st.st + vv[1].st.st + vv[2].st.st;
        if (t < ans.st) ans.st = t, ans.nd = team;
    }
    printf("%.2Lf\n", ans.st);
    for (auto x : ans.nd) printf("%s\n", x.c_str());
    return 0;
}
