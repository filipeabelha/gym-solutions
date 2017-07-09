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
const int N = 1e6+5;

int a, b;
map <int, bool> vis;
queue <pii> q;

int add (int k, int d) {
    if (k == b) return 0*printf("%d\n", d);
    if (!vis[k] and k < N) vis[k] = true, q.push(mp(k, d));
    return 1;
}

int main () {
    scanf("%d%d", &a, &b);
    q.push(mp(a, 0));
    vis[a] = 1;
    while (!q.empty()) {
        int n = q.front().st;
        int d = q.front().nd;
        q.pop();
        int k;
        k = n*2; if (!add(k, d+1)) return 0;
        k = n*3; if (!add(k, d+1)) return 0;
        k = n/2; if (!add(k, d+1)) return 0;
        k = n/3; if (!add(k, d+1)) return 0;
        k = n+7; if (!add(k, d+1)) return 0;
        k = n-7; if (!add(k, d+1)) return 0;
    }
    return 0;
}
