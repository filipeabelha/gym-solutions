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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, a, b, c, ok = 1;

int main () {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d", &a, &b, &c);
        if (a >= b+c) ok = 0;
        if (b >= a+c) ok = 0;
        if (c >= a+b) ok = 0;
    }
    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}
