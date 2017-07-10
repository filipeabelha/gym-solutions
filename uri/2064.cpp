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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int k, m, n, ans;
int f[N];
vi fav, id(N), idans;
char ch, a, b;
string s;

int main () {
    scanf("%d%d%d%c", &k, &m, &n, &ch);

    while (k--) scanf("%c", &ch), fav.pb(ch); scanf("%c", &ch);
    for (char c = 'a'; c <= 'z'; c++) id[c] = c;
    idans = id;

    getline(cin, s);
    for (int i = 0; i < m; i++) f[s[i]]++;
    for (auto c : fav) ans += f[c];

    while (n--) {
        scanf("%c%c%c%c", &a, &ch, &b, &ch);
        swap(f[b], f[a]);
        for (char c = 'a'; c <= 'z'; c++)
            if      (id[c] == a) id[c] = b;
            else if (id[c] == b) id[c] = a;
        int sum = 0;
        for (auto c : fav) sum += f[c];
        if (sum > ans) ans = sum, idans = id;
    }
    printf("%d\n", ans);
    for (int i = 0; i < m; i++) printf("%c", idans[s[i]]);
    printf("\n");
    return 0;
}
