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
const int M = 1e4+5;

ll n, k, cnt, mini = LINF;
map <int, int> f;

int main () {
    scanf("%lld%lld", &n, &k);
    for (int i = 0; (n >> i) > 0; i++) if ((n >> i) & 1) {
        cnt++;
        f[i]++;
        mini = min(mini, (ll)i);
    }
    if (cnt > k) printf("No\n");
    else {
        for (int i = 63; i >= mini; i--) {
            if (k-cnt >= f[i]) {
                f[i-1] += 2*f[i];
                cnt += f[i];
                f[i] = 0;
                mini = min(mini, (ll)(i-1));
            } else break;
        }

        while (cnt < k) {
            f[mini]--;
            f[mini-1] += 2;
            cnt++;
            mini--;
        }

        printf("Yes\n");
        for (int i = 63; i >= mini; i--) {
            int z = f[i];
            while (z--) printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
