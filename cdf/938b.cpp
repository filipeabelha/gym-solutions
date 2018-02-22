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

int n, v[N], a, b;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    int l = 1, r = 1e6, a = 0, b = n+1;
    int cnt = 0;
    while (++cnt) {
        l++;
        r--;
        if (v[a+1] == l) a++;
        if (v[b-1] == r) b--;
        if (a >= b-1) break;
    }
    printf("%d\n", cnt);
    return 0;
}
