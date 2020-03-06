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

string s;

bool is_divisible (char a, char b) {
    int x = (b-'0') + 10*(a-'0');
    return (x % 4) == 0;
}

bool is_divisible2 (char c) {
    int x = (c-'0');
    return (x % 4) == 0;
}

ll ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    ans += is_divisible2(s[0]);
    for (int i = 1; i < s.size(); i++) {
        ans += is_divisible2(s[i]);
        if (is_divisible(s[i-1], s[i])) {
            ans += i;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
