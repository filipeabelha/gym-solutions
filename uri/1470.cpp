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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

int n, m, x;
queue <vi> q;

int main () {
    while (~scanf("%d", &n)) {
        while (!q.empty()) q.pop();

        vi u, v;

        for (int i = 0; i < n; i++) scanf("%d", &x), u.pb(x);
        q.push(u);
        scanf("%d", &m);
        for (int i = 0; i < m; i++) scanf("%d", &x), v.pb(x);

        int ok = 0;

        while (!q.empty()) {
            vi t = q.front(); q.pop();

            if (t.size() == m) {
                int eq = 1;
                for (int j = 0; j < m; j++)
                    if (t[j] != v[j]) eq = 0;
                if (eq) ok = 1;
                eq = 1;
                for (int j = 0; j < m; j++)
                    if (t[m-j-1] != v[j]) eq = 0;
                if (eq) ok = 1;
            }
            if (ok) break;

            for (int d = 1; d <= t.size()/2; d++) {
                vi z = t;
                for (int i = 0; i < d; i++)
                    z[2*d-i-1] += z[i];
                z.erase(z.begin(), z.begin()+d);
                if (z.size() >= m) q.push(z);
            }
            for (int d = 1; d <= t.size()/2; d++) {
                vi z = t;
                for (int i = 0; i < d; i++)
                    z[t.size()-2*d+i] += z[t.size()-i-1];
                z.erase(z.begin()+z.size()-d, z.begin()+z.size());
                if (z.size() >= m) q.push(z);
            }
        }

        printf("%s\n", ok ? "S" : "N");
    }
    return 0;
}
