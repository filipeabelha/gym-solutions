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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e5+10;

int from, to, ans;

int inv (int x) {
    string y = to_string(x);
    reverse(y.begin(), y.end());
    return atoi(y.c_str());
}

int main () {
    int tc; scanf("%d", &tc); while (tc--) {
        map <int, int> vis; ans = -1;
        priority_queue <pii> pq;
        scanf("%d%d", &from, &to);
        vis[from] = 1;
        pq.push(mp(0, -from));
        while (!pq.empty()) {
            int x = -pq.top().nd;
            int d = -pq.top().st; pq.pop();
            if (x == to) {ans = d; break;}
            int a = inv(x);
            int b = ++x; ++d;
            if (!vis[a]) pq.push(mp(-d, -a)), vis[a] = 1;
            if (!vis[b]) pq.push(mp(-d, -b)), vis[b] = 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
