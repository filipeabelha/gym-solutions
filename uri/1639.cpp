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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e4+10;

int x, vis[N], ans;

int cnt (int u) {
    if (vis[u]) return ans;
    vis[u] = 1;
    ans++;
    return cnt(((u*u)/100)%10000);
}

int main () {
    while (~scanf("%d", &x) and x) {
        ans = 0;
        cl(vis, 0);
        printf("%d\n", cnt(x));
    }
    return 0;
}
