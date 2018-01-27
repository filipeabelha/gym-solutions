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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, v[N], st[N];
ll sum;

int main () {
    freopen("hell.in", "r", stdin);
    freopen("hell.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    if (sum & 1) return 0*printf("No\n");
    printf("Yes\n");
    sum /= 2;
    cl(st, -1);

    int i = 1;
    while (sum > 0) {
        st[i] = 1;
        sum -= v[i++];
    }

    sum = -sum;

    while (sum > 0) {
        st[sum] = -1;
        sum -= v[sum];
    }
    for (int i = 1; i <= n; i++) printf("%d ", st[i]);
    printf("\n");

    return 0;
}
