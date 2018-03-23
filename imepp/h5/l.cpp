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
const int N = 1e5+5;

map <string, int> id;
map <int, string> idt;
set <int> adj[N];
priority_queue <int, vector <int>, greater <int> > pq;
vi tsort;
int inc[N], n, m, tc, cnt;
string s, t;

int main () {
    while (cin >> n and ++tc) {
        id.clear();
        idt.clear();
        for (int i = 0; i < N; i++) adj[i].clear();
        tsort.clear();
        cl(inc, 0);
        cnt = 0;

        for (int i = 1; i <= n; i++) {
            cin >> s;
            if (!id.count(s)) {
                id[s] = ++cnt;
                idt[cnt] = s;
            }
        }

        cin >> m;
        while (m--) {
            cin >> s >> t;
            if (!adj[id[s]].count(id[t])) {
                adj[id[s]].insert(id[t]);
                inc[id[t]]++;
            }
        }

        for (int i = 1; i <= n; i++) if (!inc[i]) pq.push(i);

        while (!pq.empty()) {
            int u = pq.top(); pq.pop();
            for (int v : adj[u])
                if (inc[v] > 0 and !(--inc[v]))
                    pq.push(v);
            tsort.pb(u);
        }

        printf("Case #%d: Dilbert should drink beverages in this order: ", tc);
        for (int i = 0; i < tsort.size(); i++) {
            printf("%s", idt[tsort[i]].c_str());
            if (i < tsort.size()-1) printf(" ");
        }
        printf(".\n\n");
    }
    return 0;
}
