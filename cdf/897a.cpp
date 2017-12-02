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

int n, m, l, r;
char s[N], c1, c2;

int main () {
    scanf("%d%d ", &n, &m);
    scanf(" %s", s);
    for (int i = 0; i < m; i++) {
        scanf(" %d %d %c %c", &l, &r, &c1, &c2);
        l--;
        r--;
        for (int j = l; j <= r; j++)
            if (s[j] == c1) s[j] = c2;
    }
    printf("%s\n", s);
    return 0;
}
