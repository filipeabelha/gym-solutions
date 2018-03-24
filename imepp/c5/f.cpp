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
const int N = 1e3+5;

int n, k, cnt, tc;
map <string, int> id;
map <int, string> idt;
string s, t;
vi adj[N], ans;
int inc[N];

int main () {
    while (cin >> n and n and ++tc) {
        printf("Teste %d\n", tc);

        id.clear();
        idt.clear();
        cnt = 0;
        cl(inc, 0);
        for (int i = 0; i < N; i++) adj[i].clear();

        for (int i = 0; i < n; i++) {
            cin >> s;
            if (!id.count(s)) {
                id[s] = ++cnt;
                idt[cnt] = s;
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> s >> k;
            while (k--) {
                cin >> t;
                if (!id.count(t)) {
                    id[t] = ++cnt;
                    idt[cnt] = t;
                }
                adj[id[t]].pb(id[s]);
                inc[id[s]]++;
            }

        }

        queue <int> q;
        for (int i = 1; i <= n; ++i) if (!inc[i]) q.push(i);

        vi ans;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u])
                if (inc[v] > 0 and --inc[v] == 0)
                    q.push(v);
            ans.pb(u);
        }

        if (ans.size() != n) printf("impossivel\n");
        else {
            printf("%s", idt[ans[0]].c_str());
            for (int i = 1; i < ans.size(); i++)
                printf(" %s", idt[ans[i]].c_str());
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
