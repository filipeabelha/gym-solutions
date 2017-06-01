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

int n, x, l[15], c[15], d1, d2, ok = 1;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        scanf("%d", &x);
        l[i] += x;
        c[j] += x;
        if (i == j) d1 += x;
        if (i+j == n+1) d2 += x;
    }
    if (d1 != d2) ok = 0;
    for (int i = 1; i <= n; i++) if (l[i] != d1 or c[i] != d1) ok = 0;
    printf("%d\n", ok ? d1 : -1);
    return 0;
}
