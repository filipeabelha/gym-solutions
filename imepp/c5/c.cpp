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
#define gcd(x, y) __gcd((x), (y))

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
const int N = 1e2+5;

int n, cnt, x, dist[N], vis[N];
string s, t;
set <int> adj[N];
map <string, int> id;
map <int, string> idt;

int main () {
    while (cin >> n and n and ++cnt) {
        for (int i = 0; i < N; i++) adj[i].clear();
        id.clear();
        idt.clear();
        cl(dist, 63);
        cl(vis, 0);
        x = 1;

        printf("Teste %d\n", cnt);
        string p = "P. Erdos";
        id[p] = 1;
        idt[1] = p;

        while (n--) {
            vi v;
            while (1) {
                cin >> s >> t;
                char c = t.back();
                t.pop_back();
                s = s + ' ' + t;
                if (!id.count(s)) {
                    id[s] = ++x;
                    idt[x] = s;
                }
                v.pb(id[s]);
                if (c == '.') break;
            }
            for (int i = 0; i < v.size(); i++) {
                for (int j = i+1; j < v.size(); j++) {
                    adj[v[i]].insert(v[j]);
                    adj[v[j]].insert(v[i]);
                }
            }
        }

        queue <int> q;

        q.push(1);
        dist[1] = 0;

        while (q.size()) {
            int v = q.front(); q.pop();
            for (auto u : adj[v]) if (!vis[u]) {
                vis[u] = 1;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }

        vector <string> ans;
        for (int i = 2; i <= x; i++) ans.pb(idt[i]);
        sort(ans.begin(), ans.end(), [](string a, string b) {
             string aa = a;
             string bb = b;
             aa.erase(aa.begin(), aa.begin()+3);
             bb.erase(bb.begin(), bb.begin()+3);
             if (aa == bb) return a[0] < b[0];
             return aa < bb;
             });

        for (string z : ans) {
            printf("%s: ", z.c_str());
            if (dist[id[z]] == INF) printf("infinito\n");
            else printf("%d\n", dist[id[z]]);
        }
        printf("\n");

    }
    return 0;
}
