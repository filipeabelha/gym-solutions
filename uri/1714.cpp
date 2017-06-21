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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e2+10;

char m[N][N], chr;
queue <pair<piii, set<char> > > q;
set<set<char> > vis[N][N];

int dx[] = {+0, +0, -1, +1};
int dy[] = {-1, +1, +0, +0};
int n, ans = INF;

char inv (char ch) {
    if (ch >= 'A' and ch <= 'Z') return ch-'A'+'a';
    else return ch-'a'+'A';
}

int main () {
    scanf("%d%c", &n, &chr);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) scanf("%c", &m[i][j]);
        scanf("%c", &chr);
    }
    set <char> si;
    si.insert(m[1][1]);
    q.push(mp(mp(1, mp(1,1)), si));
    while (!q.empty()) {
        int d = q.front().st.st;
        int x = q.front().st.nd.st;
        int y = q.front().st.nd.nd;
        set <char> s = q.front().nd;
        q.pop();
        if (x == n and y == n) {
            ans = min(ans, d);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int dd = d+1;
            int xx = x+dx[i];
            int yy = y+dy[i];
            set <char> ss = s;
            if (xx > n) continue;
            if (xx < 1) continue;
            if (yy > n) continue;
            if (yy < 1) continue;
            if (ss.count(inv(m[xx][yy]))) continue;
            ss.insert(m[xx][yy]);
            if (vis[xx][yy].count(ss)) continue;
            vis[xx][yy].insert(ss);
            q.push(mp(mp(dd, mp(xx,yy)), ss));
        }
    }
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}
