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

int n, c, w, x, y, ok = 1;

int main () {
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        w += y-x;
        if (w > c) ok = 0;
    }
    printf("%s\n", ok ? "N" : "S");
    return 0;
}
