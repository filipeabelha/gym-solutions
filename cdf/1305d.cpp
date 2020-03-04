#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int n;
set <int> adj[N], leaves;

void ans (int k) {
    printf("! %d\n", k);
    fflush(stdout);
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].insert(b);
        adj[b].insert(a);
    }

    for (int i = 1; i <= n; i++)
        if (adj[i].size() == 1)
            leaves.insert(i);

    while (1) {
        int x = *leaves.begin();
        int y = *leaves.rbegin();

        if (x == y) {
            ans(x);
            break;
        }

        printf("? %d %d\n", x, y);
        fflush(stdout);

        int k;
        scanf("%d", &k);

        if (k == x) {
            ans(k);
            break;
        }

        if (k == y) {
            ans(k);
            break;
        }

        int xn = *adj[x].begin();
        adj[x].erase(xn);
        adj[xn].erase(x);
        leaves.erase(x);
        if (adj[xn].size() == 1) leaves.insert(xn);

        int yn = *adj[y].begin();
        if (adj[y].count(yn)) adj[y].erase(yn);
        if (adj[yn].count(y)) adj[yn].erase(y);
        if (leaves.count(y)) leaves.erase(y);
        if (adj[yn].size() == 1) leaves.insert(yn);

    }

    return 0;
}
