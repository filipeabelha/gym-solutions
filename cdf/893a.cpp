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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, v[N], d[N], s[N], ok = 1;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    d[1] = 3-v[1];
    s[1] = 3;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            if (v[i] == j and s[i-1] != j) d[i] = s[i-1];
            if (v[i] == j and s[i-1] == j) d[i] = v[i-1];
        }
        s[i] = 6-v[i]-d[i];
    }
    for (int i = 1; i <= n; i++) if (s[i] == v[i] or s[i] == d[i]) ok = 0;
    for (int i = 1; i <= n-1; i++) if (s[i+1] != d[i]) ok = 0;
    printf("%s\n", ok ? "YES" : "NO");
    //printf("V | D | S\n");
    //for (int i = 1; i <= n; i++) printf("%d | %d | %d\n", v[i], d[i], s[i]);
    return 0;
}
