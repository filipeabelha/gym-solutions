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

int c, v0, v1, a, l;

int main () {
    scanf("%d%d%d%d%d", &c, &v0, &v1, &a, &l);
    int v = v0;
    int s = 0;
    for (int t = 1; ; t++) {
        s += v;
        v = min(v1, v+a);
        if (s >= c) return 0*printf("%d\n", t);
        s -= l;
    }
    return 0;
}
