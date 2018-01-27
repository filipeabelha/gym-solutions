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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

char s[N];
string ans;
const char* let = "AEIOUBCDFGHJKLMNPQRSTVWXYZ";
int f[N], part[2][N], adj[500][500];

int main () {
    freopen("javanese.in", "r", stdin);
    freopen("javanese.out", "w", stdout);
    while (~scanf(" %s", s)) {
        ans += s;
        ans += ' ';
        int sz = strlen(s);
        for (int i = 1; i < sz; i++) {
            int u = s[i] - 'A';
            int v = s[i-1] - 'A';
            adj[u][v] = adj[v][u] = 1;
        }
    }
    vi per(26,1);
    for (int i = 0; i < 5; i++) per[i] = 0;
    int cnt = 1;
    do {
        for (int i = 0; i < 26; i++) part[per[i]][i] = cnt;

        int ok = 1;
        for (int i = 0; i < 26; i++) if (part[0][i] == cnt) for (int k = 0; k < 26; k++) if (adj[i][k] and part[0][k] == cnt) ok = 0;
        for (int i = 0; i < 26; i++) if (part[1][i] == cnt) for (int k = 0; k < 26; k++) if (adj[i][k] and part[1][k] == cnt) ok = 0;

        if (!ok) continue;

        char c = 'A';

        int i = 0;
        for (int x = 0; x < 26; x++) if (part[0][x] == cnt) f[x] = let[i++];
        for (int x = 0; x < 26; x++) if (part[1][x] == cnt) f[x] = let[i++];

        for (auto x : ans) printf("%c", x == ' ' ? ' ' : f[x-'A']);
        printf("\n");
        return 0;

    } while (cnt++ and next_permutation(per.begin(), per.end()));
    printf("impossible\n");
    return 0;
}
