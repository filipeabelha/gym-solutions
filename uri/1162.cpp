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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e2+5;

int tc, n, ans;
int v[N];

int main () {
    scanf("%d", &tc);
    while (tc--) {
        ans = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);

        int cont = 1;
        while (cont) {
            cont = 0;
            for (int i = 0; i < n-1; i++)
                if (v[i] > v[i+1]) {
                    swap(v[i], v[i+1]);
                    ans++;
                    cont = 1;
                }
        }
        printf("Optimal train swapping takes %d swaps.\n", ans);
    }
    return 0;
}
