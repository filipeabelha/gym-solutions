#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, x;
set <int> inside;
set <int> everyone;
vi ans;

int main () {
    scanf("%d", &n);
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x > 0) {
            if (!everyone.count(x)) inside.insert(x), everyone.insert(x);
            else {
                printf("-1\n");
                return 0;
            }
        } else if (x < 0 and inside.count(-x)) inside.erase(-x);
        else {
            printf("-1\n");
            return 0;
        }
        if (inside.empty()) {
            everyone.clear();
            ans.pb(cur);
            cur = 0;
        }
        cur++;
    }
    if (ans.empty() or inside.size()) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", (int) ans.size());
    for (auto x : ans) printf("%d ", x);
    printf("\n");

    return 0;
}
