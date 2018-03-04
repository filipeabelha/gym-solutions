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

int n, a, b;

int solve (int n, int a, int b) {
    if (a > b) swap(a, b);
    if (n == 2) return 1;
    if (a <= n/2 and b > n/2) return 1;
    if (a > n/2 and b > n/2) a -= n/2, b -= n/2;
    return 1+solve(n/2, a, b);
}

int main () {
    scanf("%d%d%d", &n, &a, &b);
    int h;
    if (n == 2) h = 2;
    if (n == 4) h = 3;
    if (n == 8) h = 4;
    if (n == 16) h = 5;
    if (n == 32) h = 6;
    if (n == 64) h = 7;
    if (n == 128) h = 8;
    if (n == 256) h = 9;
    int s = solve(n, a, b);
    if (s == 1) printf("Final!\n");
    else printf("%d\n", h-solve(n, a, b));
    return 0;
}
