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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 2e5+10;

int v[N], ans;

void go (int x) {
    ans++;
    if (x == 1) return;
    go(v[x]);
}

int main () {
    int n; scanf("%d", &n);
    int h = n/2;
    for (int i = 1; i <= h; i++) v[i] = 2*i;
    for (int i = h+1; i <= n; i++) v[i] = v[i-h]-1;
    go(2);
    printf("%d\n", ans);
    return 0;
}
