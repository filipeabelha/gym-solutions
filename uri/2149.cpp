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
const int N = 20;

ll f[N];
int n;

int main () {
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= 20; i++) {
        if (i&1) f[i] = f[i-1] + f[i-2];
        else f[i] = f[i-1]*f[i-2];
    }
    while (~scanf("%d", &n))
        printf("%lld\n", f[n]);
    return 0;
}
