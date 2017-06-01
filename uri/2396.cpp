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

int n, m;
priority_queue <pii> pq;

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int sum = 0, x;
        for (int j = 0; j < m; j++) scanf("%d", &x), sum += x;
        pq.push(mp(-sum, i));
    }
    for (int i = 0; i < 3; i++) printf("%d\n", pq.top().nd), pq.pop();
    return 0;
}
