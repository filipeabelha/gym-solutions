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

int n, m, ans, x;

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int goal = 1;
        for (int j = 0; j < m; j++) {
            scanf("%d", &x);
            if (!x) goal = 0;
        }
        if (goal) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
