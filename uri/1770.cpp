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

int m, k, x, v[N];
char chr;

int main () {
    while (~scanf("%d%d", &m, &k)) {
        int ans = 0, go = 1;
        set <int> s;
        for (int i = 1; i <= m; i++) scanf("%d", &v[i]);
        scanf("%c", &chr);
        for (int i = 0; i < k; i++) {
            scanf("%d", &x);
            ans += go*v[x];
            s.insert(x);
            if (s.size() == m) go = 0;
        }
        printf("%d\n", go ? -1 : ans);
    }
    return 0;
}
