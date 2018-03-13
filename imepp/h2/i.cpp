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

int a, d, u[N], v[N];

int main () {
    while (~scanf("%d%d", &a, &d) and a and d) {
        for (int i = 0; i < a; i++) scanf("%d", &u[i]);
        for (int i = 0; i < d; i++) scanf("%d", &v[i]);
        sort(u, u+a);
        sort(v, v+d);
        int mx = u[0];
        printf("%c\n", mx < v[1] ? 'Y' : 'N');
    }
    return 0;
}
