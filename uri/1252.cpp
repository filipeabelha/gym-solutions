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
const int N = 1e4+5;

int n, m, v[N];

bool srt (int a, int b) {
    if ((a%m) != (b%m)) return (a%m) < (b%m);
    if ((a&1) != (b&1)) return (a&1) > (b&1);
    if (a&1)            return a > b;
    return a < b;
}

int main () {
    while (~scanf("%d%d", &n, &m) and n and m) {
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);
        sort(v, v+n, srt);
        printf("%d %d\n", n, m);
        for (int i = 0; i < n; i++) printf("%d\n", v[i]);
    }
    printf("0 0\n");
    return 0;
}
