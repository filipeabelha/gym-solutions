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

int n, x, v[100][2];
char t;

int main () {
    while (~scanf("%d", &n)) {
        cl(v, 0);
        while (n--) {
            scanf(" %d %c", &x, &t);
            v[x][(t == 'D')]++;
        }
        int ans = 0;
        for (int i = 30; i <= 60; i++)
            ans += min(v[i][0], v[i][1]);
        printf("%d\n", ans);
    }
    return 0;
}
