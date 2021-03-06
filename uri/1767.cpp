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

const int N = 105; // Maximum number of items
const int L = 55; // Maximum value for 'limit'

int tc, ans, n, limit = 50, w[N], v[N], knap[L], pack[L], wei[L];

int main () {
    scanf("%d", &tc);
    while (tc--) {
        cl(w, 0); cl(v, 0); cl(knap, 0); cl(pack, 0); cl(wei, 0);
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &v[i], &w[i]);
        for (int i = 0; i < n; i++)
            for (int j = L-1; j >= w[i]; j--) {
                if (v[i]+knap[j-w[i]] > knap[j]) {
                    pack[j] = 1+pack[j-w[i]];
                    wei[j] = w[i]+wei[j-w[i]];
                }
                knap[j] = max(knap[j], v[i]+knap[j-w[i]]);
            }
        ans = knap[limit];
        printf("%d brinquedos\n", ans);
        printf("Peso: %d kg\n", wei[limit]);
        printf("sobra(m) %d pacote(s)\n", n-pack[limit]);
        printf("\n");
    }
}
