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

int v[5], ans[5];

int pairi() {
    if (v[0] == v[1] and v[0] != v[2]) return v[0];
    return 0;
}

int pairii() {
    if (v[1] == v[2] and v[0] != v[1]) return v[1];
    return 0;
}

int almostset() {
    if (pairi() == v[2]+1) return pairi();
    if (pairii() == v[0]+1) return pairii();
    return 0;
}

int isset() {
    if (v[0] == v[1] and v[0] == v[2]) return v[0];
    return 0;
}

int main () {
    while (1) {
        scanf("%d%d%d", &v[0], &v[1], &v[2]);
        if (!v[0] and !v[1] and !v[2]) break;

        int maxi = 0;
        sort(v, v+3); ans[0] = ans[1] = 1, ans[2] = 2;

        if (isset() == 13) maxi = 1;
        else if (isset()) {
            ans[0] = isset()+1;
            ans[1] = isset()+1;
            ans[2] = isset()+1;
        } else if (almostset() == 13) {
            ans[0] = ans[1] = ans[2] = 1;
        } else if (pairi()) {
            ans[0] = pairi();
            ans[1] = pairi();
            ans[2] = v[2]+(almostset() ? 2 : 1);
            if (ans[2] > 13) ans[0]++, ans[1]++, ans[2] = 1;
        } else if (pairii()) {
            ans[0] = v[0]+(almostset() ? 2 : 1);
            ans[1] = pairii();
            ans[2] = pairii();
            if (ans[0] > 13) ans[1]++, ans[2]++, ans[0] = 1;
        }

        sort(ans, ans+3);

        if (maxi) printf("*\n");
        else printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    }
    return 0;
}
