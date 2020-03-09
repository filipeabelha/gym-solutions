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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, sum, s[N];

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        sum += s[i];
        s[i] += s[i-1];
    }

    if (sum % 3 != 0) {
        printf("0\n");
        return 0;
    }

    sum /= 3;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (binary_search(s+1, s+1+n, s[i]-sum) and
            binary_search(s+1, s+1+n, s[i]+sum)) ans++;
    }

    printf("%d\n", ans);

    return 0;
}
