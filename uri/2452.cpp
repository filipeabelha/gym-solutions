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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

vi v;
int f, r, x, ans;

int main () {
    scanf("%d%d", &f, &r);
    v.pb(0);
    while (r--) scanf("%d", &x), v.pb(x);
    v.pb(f+1);
    for (int i = 2; i < v.size()-1; i++) ans = max(ans, v[i]-v[i-1]-1);
    ans = max((ans/2)+(ans&1), max(v[1]-v[0]-1, v[v.size()-1]-v[v.size()-2]-1));
    printf("%d\n", ans);
    return 0;
}
