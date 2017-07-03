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

int n, m, x, ans = INF;
char s[N], t[N], chr;
vi ians;

int main () {
    scanf("%d%d%c%s%c%s", &n, &m, &chr, s, &chr, t);
    for (int st = 0; st <= m-n; st++) {
        int x = 0;
        vi ind;
        for (int i = 0; i < n; i++) if (s[i] != t[st+i])
            ind.pb(i+1), x++;
        if (x < ans) {
            ans = x;
            ians = ind;
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < ians.size(); i++) printf("%d%s", ians[i], i < ians.size()-1 ? " " : "\n");
    return 0;
}
