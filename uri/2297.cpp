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

int cnt, a, b, n, x, y;

int main () {
    while (++cnt) {
        scanf("%d", &n); if (!n) break; a = b = 0;
        while (n--) scanf("%d%d", &x, &y), a += x, b += y;
        printf("Teste %d\n%s\n\n", cnt, a > b ? "Aldo" : "Beto");
    }
    return 0;
}
