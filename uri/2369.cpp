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

int n, x = 11, ans = 7;

int main () {
    scanf("%d", &n);
    while (x <= n) {
        if (x <= 30)                  ans += 1;
        else if (x > 30 and x <= 100) ans += 2;
        else if (x > 100)             ans += 5;
        x++;
    }
    printf("%d\n", ans);
    return 0;
}
