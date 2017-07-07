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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 40;

int n, w, h, l, m[N][N];
int x, y, ans = -1;
char c;

priority_queue <pair< int, vector <pii> > > pq;
map <vector <pii>, int> vis;

int val (int a, int b, vector <pii> stat) {
    for (int i = 1; i <= n; i++)
        if (stat[i].st == a and stat[i].nd == b) return 0;
    return 1;
}

int main () {
    while (~scanf("%d%d%d%d%c", &n, &w, &h, &l, &c)) {
        while (!pq.empty()) pq.pop();
        vis.clear();
        cl(m, -1);
        ans = -1;

        vector <pii> stat(5);
        for (int i = 15+1; i <= 15+h; i++) {
            for (int j = 15+1; j <= 15+w; j++) {
                scanf("%c", &c);
                if (c == '.')              m[i][j] = 0;
                if (c == 'X')              m[i][j] = 0, x = i, y = j;
                if (c >= '0' and c <= '9') m[i][j] = 0, stat[c-'0'].st = i, stat[c-'0'].nd = j;
            }
            scanf("%c", &c);
        }

        vis[stat] = 1;
        pq.push(mp(0, stat));

        while (!pq.empty()) {
            vector <pii> stat = pq.top().nd;
            int d = -pq.top().st;
            pq.pop();
            if (stat[1].st == x and stat[1].nd == y) {
                ans = d;
                break;
            }
            for (int i = 1; i <= n; i++) {
                int no, so, we, ea;
                no = so = stat[i].st; we = ea = stat[i].nd;
                while (!m[no-1][stat[i].nd] and val(no-1, stat[i].nd, stat)) no--;
                while (!m[so+1][stat[i].nd] and val(so+1, stat[i].nd, stat)) so++;
                while (!m[stat[i].st][we-1] and val(stat[i].st, we-1, stat)) we--;
                while (!m[stat[i].st][ea+1] and val(stat[i].st, ea+1, stat)) ea++;

                vector <pii> statno = stat; statno[i].st = no;
                if (!vis[statno] and d < l) vis[statno] = 1, pq.push(mp(-d-1, statno));

                vector <pii> statso = stat; statso[i].st = so;
                if (!vis[statso] and d < l) vis[statso] = 1, pq.push(mp(-d-1, statso));

                vector <pii> statwe = stat; statwe[i].nd = we;
                if (!vis[statwe] and d < l) vis[statwe] = 1, pq.push(mp(-d-1, statwe));

                vector <pii> statea = stat; statea[i].nd = ea;
                if (!vis[statea] and d < l) vis[statea] = 1, pq.push(mp(-d-1, statea));
            }

        }
        (ans == -1 ? puts("NO SOLUTION") : printf("%d\n", ans));
    }
    return 0;
}
