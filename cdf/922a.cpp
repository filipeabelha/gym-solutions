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

int a, b;

int solve (int x, int y) {
    if (b == 0)            return 0;
    if (a == 0 and b == 1) return 1;
    if (b == 1)            return 0;
    if (a == 0)            return 0;
    if (b-a == 1)          return 1;
    if (a > b and (a-b)&1) return 1;
    return 0;
}

int main () {
    scanf("%d%d", &a, &b);
    printf("%s\n", solve(a, b) ? "Yes" : "No");
    return 0;
}
