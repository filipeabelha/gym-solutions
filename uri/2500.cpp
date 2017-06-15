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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e3+10;

int n, m, k, x;

int main () {
    while (~scanf("%d%d%d", &n, &m, &k) and n and m and k) {
        k -= m % n;
        if (k < 1) k += n;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (i == k) printf("%d\n", x);
        }
    }
    return 0;
}
