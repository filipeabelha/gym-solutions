#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;

const int N = 1e6+1, K = 26;
int sl[2*N], len[2*N], sz, last;
ll cnt[2*N];
map <int, int> adj[2*N];

void add (int c) {
    int u = sz++;
    len[u] = len[last] + 1;
    cnt[u] = 1;

    int p = last;
    while (p != -1 and !adj[p][c])
        adj[p][c] = u, p = sl[p];

    if (p == -1) sl[u] = 0;
    else {
        int q = adj[p][c];
        if (len[p]+1 == len[q]) sl[u] = q;
        else {
            int r = sz++;
            len[r] = len[p]+1;
            sl[r] = sl[q];
            adj[r] = adj[q];
            while(p != -1 and adj[p][c] == q)
                adj[p][c] = r, p = sl[p];
            sl[q] = sl[u] = r;
        }
    }

    last = u;
}

void clear() {
    for(int i = 0; i <= sz; ++i) adj[i].clear();
    last = 0;
    sz = 1;
    sl[0] = -1;
}

void build (string& s) {
    clear();
    for (auto c : s) add(c);
}

string s, t;
int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> n;

    build(s);

    while (n--) {
        cin >> t;
        int ans = 0;
        bool ok = true;

        int u = 0;
        for (int i = 0; i < t.size(); i++) {
            char c = t[i];
            int v = adj[u][c];

            if (!u and !v) {
                ok = false;
                break;
            }

            if (!v) {
                u = 0;
                ans++;
                i--;
                continue;
            }

            u = v;
        }
        if (u) ans++;

        if (!ok) ans = -1;
        cout << ans << "\n";
    }

    return 0;
}
