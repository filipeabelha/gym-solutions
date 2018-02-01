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
const int N = 2e5+5;

int n, m, a, b, inc[N], cnt;
char ca, cb;

vi adj[N], v;
queue <int> q;

int main () {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf(" %c %d %c %d", &ca, &a, &cb, &b);

        a *= 2;
        b *= 2;

        if (ca == '-') a++;
        if (cb == '-') b++;

        adj[a].pb(b^1);
        adj[b].pb(a^1);

        inc[a^1]++;
        inc[b^1]++;

    }

    for (int i = 2; i <= 2*n+1; i++) if (!inc[i]) q.push(i);

    while (q.size()) {
        int e = q.front(); q.pop();

        for (auto x : adj[e])
            if (inc[x] > 0 and !(--inc[x]))
                q.push(x);

        cnt++;
    }
    printf("%s\n", (cnt == 2*n ? "TAK" : "NIE"));

    return 0;
}
