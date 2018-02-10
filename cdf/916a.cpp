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

int n, a, b, ans;

int lucky (int a, int b) {
    if (b < 0) b += 60, a -= 1;
    if (a < 0) a += 24;
    if (a/10 == 7) return 0;
    if (b/10 == 7) return 0;
    if (a%10 == 7) return 0;
    if (b%10 == 7) return 0;
    return 1+lucky(a, b-n);
}

int main () {
    scanf("%d%d%d", &n, &a, &b);
    printf("%d\n", lucky(a, b));
    return 0;
}
