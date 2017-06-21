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

int n1, n2, d, a, b, inc[3][N];
vii adj(N);
queue <int> q1, q2, q3, q4;

int main () {
    while (~scanf("%d%d%d", &n1, &n2, &d) and n1) {
        while (d--) {
            scanf("%d%d", &a, &b);
            adj[b].pb(a);
            inc[1][a]++;
            inc[2][a]++;
        }

        for (int i = 1; i <= n1+n2; i++) if(!inc[1][i]) {
            if (i <= n1) q1.push(i), q3.push(i);
            else q2.push(i), q4.push(i);
        }

        int ans = 0;
        int sum = 1;
        while (1) {
            if (q1.empty() and q2.empty()) break;

            while (!q1.empty()) {
                int u = q1.front(); q1.pop();
                for (int v : adj[u]) {
                    if (inc[1][v] > 0 and !(--inc[1][v])) {
                        v <= n1 ? q1.push(v) : q2.push(v);
                    }
                }
            }
            sum++;

            if (q1.empty() and q2.empty()) break;

            while (!q2.empty()) {
                int u = q2.front(); q2.pop();
                for (int v : adj[u]) {
                    if (inc[1][v] > 0 and !(--inc[1][v])) {
                        v <= n1 ? q1.push(v) : q2.push(v);
                    }
                }
            }
            sum++;
        }

        ans = sum;
        sum = 1;
        while (1) {
            if (q3.empty() and q4.empty()) break;

            while (!q4.empty()) {
                int u = q4.front(); q4.pop();
                for (int v : adj[u]) {
                    if (inc[2][v] > 0 and !(--inc[2][v])) {
                        v <= n1 ? q3.push(v) : q4.push(v);
                    }
                }
            }
            sum++;

            if (q3.empty() and q4.empty()) break;

            while (!q3.empty()) {
                int u = q3.front(); q3.pop();
                for (int v : adj[u]) {
                    if (inc[2][v] > 0 and !(--inc[2][v])) {
                        v <= n1 ? q3.push(v) : q4.push(v);
                    }
                }
            }
            sum++;
        }

        ans = min(ans, sum);

        printf("%d\n", ans);

        for (int i = 0; i < N; i++) adj[i].clear();
    }
    return 0;
}
