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

int sz, z[N], p[N];

int main () {
    scanf("%d", &sz);
    for (int i = 0; i < sz; i++) scanf("%d", &z[i]);
    for (int i = 0; i < sz; i++) p[i+z[i]-1] = max(p[i+z[i]-1], z[i]);
    for (int i = sz-2; i >= 0; i--) p[i] = max(p[i], p[i+1]-1);
    for (int i = 0; i < sz; i++) printf("%d ", p[i]); printf("\n");
    return 0;
}
