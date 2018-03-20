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
#define gcd(x, y) __gcd((x), (y))

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
const int N = 1e7+5;

int t, n, a, b, x, y;
int sz[N], par[N];
char c, o;
string s;

int find (int x) {return par[x] == x ? x : x = find(par[x]);}

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[b] > sz[a]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

void query (int a, int b) {
    if ((a = find(a)) == (b = find(b))) x++;
    else y++;
}

int main () {
    scanf("%d", &t);
    cin.ignore();
    getline(cin, s);
    while (t--) {
        for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
        x = y = 0;

        getline(cin, s);
        sscanf(s.c_str(), "%d", &n);
        while (1) {
            getline(cin, s);
            if (s.size() < 3) break;
            sscanf(s.c_str(), " %c %d %d ", &c, &a, &b);
            if (c == 'c') unite(a, b);
            else query(a, b);
            if (o == '\n') break;
        }
        printf("%d,%d\n", x, y);
        if (t) printf("\n");
    }
    return 0;
}
