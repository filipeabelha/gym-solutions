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
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;
int a[N], sum;
set <int> ind[N];

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        ind[a[i]].insert(i);
    }
    sum /= (n/2);
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        int y = sum-a[i];
        if (ind[x].size() and ind[y].size()) {
            auto u = ind[x].begin();
            auto v = ind[y].rbegin();
            printf("%d %d\n", *u, *v);
            ind[x].erase(ind[x].find(*u));
            ind[y].erase(ind[y].find(*v));
        }
    }
    return 0;
}
