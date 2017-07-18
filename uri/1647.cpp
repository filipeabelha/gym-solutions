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

int n, v[N];
ll ans;

int main () {
    while (~scanf("%d", &n) and n) {
        ans = 0;
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);
        for (int i = n-1; i >= 0; i--) {
            for (int j = i-1; j >= 0; j--) v[j] += v[i];
            ans += v[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
