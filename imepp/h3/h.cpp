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

ll s, n, v[30], ok[30], okans[30];
ll minDiff;

void bt (ll ind, ll sum) {
    ok[ind] = 1;
    if (sum > s) {
        ok[ind] = 0;
        return;
    }
    if (minDiff > s-sum) {
        minDiff = s-sum;
        for (int i = 0; i < n; i++) okans[i] = ok[i];
    }
    for (int i = ind+1; i < n; i++) bt(i, sum+v[i]);
    ok[ind] = 0;
}


int main () {
    while (~scanf("%lld%lld", &s, &n)) {
        cl(ok, 0);
        cl(okans, 0);
        for (int i = 0; i < n; i++) scanf("%lld", &v[i]);
        minDiff = INF;
        for (int i = 0; i < n; i++) bt(i, v[i]);
        for (int i = 0; i < n; i++) if (okans[i])
            printf("%lld ", v[i]);
        printf("sum:%lld\n", s-minDiff);
    }

    return 0;
}
