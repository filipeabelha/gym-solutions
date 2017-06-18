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

const int A = 2e3+10;

int v[A], coin[A], tc, maxi, n = 6;

int main () {
    scanf("%d" , &tc);
    while (tc--) {
        cl(v, 0);

        for (int i = 0; i < n; i++) scanf("%d" , &v[i]);

        cl(coin, 63);
        coin[0] = 0;

        for (int i = 0; i < n; i++)
            for (int j = v[i]; j < A; j++)
                coin[j] = min(coin[j], 1+coin[j-v[i]]);

        for (int i = 0; i < n; i++)
            for (int j = A-v[i]-1; j >= 0; j--)
                coin[j] = min(coin[j], 1+coin[j+v[i]]);

        maxi = 0;
        ll ans = 0;

        for (int i = 1; i <= 100; i++) {
            ans += coin[i];
            maxi = max(maxi, coin[i]);
        }

        printf("%lld.%.2lld %d\n", ans/100, ans%100, maxi);
    }
    return 0;
}
