#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int tc, n, x;
char s[N];
deque <int> d;

int main () {
    scanf("%d", &tc);
    while (tc--) {
        scanf(" %s", s);
        scanf("%d", &n);
        char c;
        scanf(" %*c");
        for (int i = 0; i < n; i++) {
            scanf(" %d%*c", &x);
            d.pb(x);
        }
        if (n == 0) scanf(" %*c");
        int sz = strlen(s);
        int side = 1;
        int ok = 1;
        for (int i = 0; i < sz; i++) {
            if (s[i] == 'D' and d.empty()) {
                printf("error\n");
                ok = 0;
                break;
            }
            if (s[i] == 'D' and  side) d.pop_front();
            if (s[i] == 'D' and !side) d.pop_back();
            if (s[i] == 'R') side ^= 1;
        }

        if (ok) {
            printf("[");
            if (d.size()) {
                if (side) {
                    printf("%d", d.front());
                    d.pop_front();
                    while (d.size()) {
                        printf(",%d", d.front());
                        d.pop_front();
                    }
                } else {
                    printf("%d", d.back());
                    d.pop_back();
                    while (d.size()) {
                        printf(",%d", d.back());
                        d.pop_back();
                    }
                }
            }
            printf("]\n");
        }
    }

    return 0;
}
