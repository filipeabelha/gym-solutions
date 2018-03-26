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

int n, ok;

int main () {
    while (~scanf("%d", &n) and n) {
        if (ok) printf("\n");
        ok = 1;

        vi v(n);
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);

        for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
        for (int k = j+1; k < n; k++)
        for (int l = k+1; l < n; l++)
        for (int m = l+1; m < n; m++)
        for (int o = m+1; o < n; o++)
            printf("%d %d %d %d %d %d\n",
            v[i], v[j], v[k], v[l], v[m], v[o]);
    }
    return 0;
}
