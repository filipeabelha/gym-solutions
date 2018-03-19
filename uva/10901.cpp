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

int tc, n, t, m, k, ans;
int a[N];
char ch[N];
queue <pii> q[2];
set <int> s;

void load (int i) {
    s.clear();
    while (q[i].size() and q[i].front().st <= ans and s.size() < n){
        s.insert(q[i].front().nd);
        q[i].pop();
    }
}

void go (int i) {
    load(i);
    if (s.empty()) {
        if (q[i].size() and (q[i^1].empty() or q[i^1].front().st >= q[i].front().st)) {
            ans = q[i].front().st;
            load(i);
        } else if (q[i^1].size() and q[i^1].front().st > ans) ans = q[i^1].front().st;
    }
    ans += t;
    for (auto x : s) a[x] = ans;
}

int main () {
    scanf("%d", &tc);
    while (tc--) {
        ans = 0;
        scanf(" %d %d %d", &n, &t, &m);
        for (int i = 1; i <= m; i++) {
            scanf(" %d %s", &k, ch);
            q[(ch[0] == 'r')].push({k, i});
        }
        while (1) {
            if (q[0].size() or q[1].size()) go(0); else break;
            if (q[0].size() or q[1].size()) go(1); else break;
        }
        for (int i = 1; i <= m; i++) printf("%d\n", a[i]);
        if (tc) printf("\n");
    }
    return 0;
}
