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

int tc, n;
char x, y, c;

int main () {
    scanf("%d", &tc);
    while (tc--) {
        int r, g, b;
        r = g = b = 0;
        scanf("%d%c", &n, &c);
        while (n--) {
            scanf("%c %c%c", &x, &y, &c);
            if (x == 'R' and y == 'G') r += 2;
            if (x == 'G' and y == 'B') g += 2;
            if (x == 'B' and y == 'R') b += 2;
            if (x == 'G' and y == 'R') g += 1;
            if (x == 'B' and y == 'G') b += 1;
            if (x == 'R' and y == 'B') r += 1;
        }
        if (r > g and r > b)        printf("red\n");
        else if (g > r and g > b)   printf("green\n");
        else if (b > r and b > g)   printf("blue\n");
        else if (r == g and g == b) printf("trempate\n");
        else                        printf("empate\n");
    }
    return 0;
}
