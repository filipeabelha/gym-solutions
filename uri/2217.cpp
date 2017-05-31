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

int tc, l, ans, b;

int main () {
    scanf("%d", &tc); while (tc--) {
        scanf("%d", &l);
        ans = 1, b = 9;
        while (l) {
            if (l&1) ans = ans*b % 10;
            b = b*b % 10;
            l /= 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
