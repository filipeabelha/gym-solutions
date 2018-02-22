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

int a, b, ans, maxi;

int dgt (int x) {
    if (x == 0) return 1;
    int r = 0;
    while (x) {
        int d = x%10;
        x /= 10;
        if (d == 8) r += 2;
        if (d == 0 or d == 6 or d == 9) r++;
    }
    return r;
}

int main () {
    scanf("%d%d", &a, &b);
    ans = a;
    for (int i = a; i <= b; i++) {
        if (maxi < dgt(i)) {
            maxi = dgt(i);
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
