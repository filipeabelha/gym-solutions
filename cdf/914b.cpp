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

int n, v[N], f[N];

int solve (int l, int r) {
    int m = v[r];
    if (f[m]&1) return 1;
    if (v[l] == v[r] and (r-l+1)&1) return 1;
    if (v[l] == v[r]) return 0;
    return solve(l, r-f[m]);
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]), f[v[i]]++;
    sort(v+1, v+1+n);
    printf("%s\n", solve(1, n) ? "Conan" : "Agasa");
    return 0;
}
