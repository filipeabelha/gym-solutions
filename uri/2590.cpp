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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e7+10;

int exp(int e) {
    int m = e&3;
    if (m == 0) return 1;
    if (m == 1) return 7;
    if (m == 2) return 9;
    if (m == 3) return 3;
}

int t, x, ans[N];

int main () {
    while (~scanf("%d", &t)) {
        while (t--) {
            scanf("%d", &x);
            if (x < N) ans[x] = exp(x);
            printf("%d\n", x < N ? ans[x] : exp(x));
        }
    }
    return 0;
}
