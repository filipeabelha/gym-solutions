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

int n, m;
int vis[N], comp, ans, lef;
string s, t;
set <char> let;
set <char> adj[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m) {
        for (int i = 0; i < N; i++) adj[i].clear();
        cl(vis, 0);
        ans = 0;
        let.clear();

        cin >> t;

        comp = n;
        lef = n;
        while (m--) {
            cin >> s;
            let.insert(s[0]);
            let.insert(s[1]);
            adj[s[0]].insert(s[1]);
            adj[s[1]].insert(s[0]);
        }

        for (auto c : t) vis[c] = 1, lef--;
        while (lef) {
            vector <char> mark;
            for (auto d : let) if (!vis[d]) {
                int cnt = 0;
                for (auto e : let)
                    if (e != d and adj[e].count(d) and vis[e]) cnt++;
                if (cnt >= 3) mark.pb(d);
            }
            for (auto c : mark) vis[c] = 1, lef--;
            if (mark.empty()) break;
            ans++;
        }
        if (lef) printf("THIS BRAIN NEVER WAKES UP\n");
        else     printf("WAKE UP IN, %d, YEARS\n", ans);
    }
    return 0;
}
