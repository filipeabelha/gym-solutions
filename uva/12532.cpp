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
const int N = 1e5+5;

int bit[N][3];

void add (int p, int v, int i) {
    for (p += 2; p < N; p += p&-p) bit[p][i] += v;
}

int query (int p, int i) {
    int r = 0;
    for (p += 2; p; p -= p&-p) r += bit[p][i];
    return r;
}

int n, q, x, y, v[N];
string ans;
char c;

int main () {
    while (~scanf("%d%d", &n, &q)) {
        ans = "";
        cl(bit, 0);
        cl(v, 0);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (x > 0)  add(i, 1, 0);
            if (x < 0)  add(i, 1, 1);
            if (x == 0) add(i, 1, 2);
            v[i] = x;
        }

        while (q--) {
            scanf(" %c %d %d", &c, &x, &y);
            if (c == 'C') {
                if (v[x] > 0)  add(x, -1, 0);
                if (v[x] < 0)  add(x, -1, 1);
                if (v[x] == 0) add(x, -1, 2);
                if (y > 0)     add(x, 1, 0);
                if (y < 0)     add(x, 1, 1);
                if (y == 0)    add(x, 1, 2);
                v[x] = y;
            }
            if (c == 'P') {
                int a = query(y, 0) - query(x-1, 0);
                int b = query(y, 1) - query(x-1, 1);
                int c = query(y, 2) - query(x-1, 2);
                if (c) ans.pb('0');
                else if (b&1) ans.pb('-');
                else ans.pb('+');
            }
        }

        printf("%s\n", ans.c_str());
    }
    return 0;
}
