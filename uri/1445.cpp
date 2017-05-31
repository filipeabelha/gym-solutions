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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e3+10;

int n, x[N], y[N];
char chr;
set <int> s;

int main () {
    while (1) {
        scanf("%d%c", &n, &chr); if (!n) break;
        s.clear(); s.insert(1);
        for (int i = 0; i < n; i++) scanf("(%d,%d)%c", &x[i], &y[i], &chr);
        while (1) {
            int buf = 0;
            for (int i = 0; i < n; i++) {
                if (s.count(x[i]) and !s.count(y[i])) s.insert(y[i]), buf++;
                else if (s.count(y[i]) and !s.count(x[i])) s.insert(x[i]), buf++;
            }
            if (!buf) break;
        }
        printf("%d\n", (int) s.size());
    }
    return 0;
}
