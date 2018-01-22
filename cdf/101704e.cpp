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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LMOD = 1011112131415161719ll;
const int N = 1e5+5;

int n;
vi v;
queue <vi> q;
vector <vi> ans;
map <vi, bool> vis;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) v.pb(-1);
    vis[v] = 1;
    q.push(v);
    ans.pb(v);
    while (q.size()) {
        v = q.front(); q.pop();
        for (int i = 0; i < v.size(); i++) {
            vi vv;
            for (int j = 0; j < v.size(); j++)
                if (i != j) vv.pb(v[j]);
            for (int j = 0; j < vv.size(); j++) {
                vi s = vv;
                s[j] += v[i];
                sort(s.begin(), s.end());
                if (!vis[s]) {
                    q.push(s);
                    ans.pb(s);
                    vis[s] = 1;
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto p : ans) {
        for (int j = 0; j < p.size(); j++) {
            printf("%d%s", -p[j], j < p.size()-1 ? "+" : "\n");
        }
    }

    return 0;
}
