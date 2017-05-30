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
const int N = 1e4;

int tc, x, n, strt, chl[N], chr[N];

void add (int z, int where) {
    if (z > where) {
        if (chr[where] >= 0) add(z, chr[where]);
        else chr[where] = z;
    } else if (z < where) {
        if (chl[where] >= 0) add(z, chl[where]);
        else chl[where] = z;
    }
}

int main () {
    scanf("%d", &tc); for (int i = 1; i <= tc; i++) {
        cl(chl, -1); cl(chr, -1);
        scanf("%d%d", &n, &strt); n--;
        while (n--) scanf("%d", &x), add(x, strt);
        printf("Case %d:\n", i);
        queue <int> q;
        q.push(strt);
        while (!q.empty()) {
            int a = q.front(); q.pop();
            if (chl[a] >= 0) q.push(chl[a]);
            if (chr[a] >= 0) q.push(chr[a]);
            printf("%d%s", a, q.empty() ? "\n\n" : " ");
        }
    }
    return 0;
}
