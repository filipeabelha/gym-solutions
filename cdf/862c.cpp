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
const int N = 1e6;
const int M = 1e5;

int n, x, xsum;
set <int> s;

void print() {
    int xsum = 0;
    for (auto k : s) xsum ^= k;
    assert(s.size() == n);
    assert(xsum == x);

    printf("YES\n");
    for (auto x : s) printf("%d ", x);
    printf("\n");
}

int main () {
    scanf("%d%d", &n, &x);

    if (n == 1) {
        s.insert(x);
        print();
        return 0;
    }

    if (n == 2) {
        if (x > 0) {
            s.insert(x);
            s.insert(0);
            print();
            return 0;
        }

        if (x == 0) {
            printf("NO\n");
            return 0;
        }
    }

    if (n == 3) {
        s.insert((1 << 18)|x);
        s.insert((1 << 17)|0);
        s.insert((1 << 18)|(1 << 17)|0);
        print();
        return 0;
    }

    s.insert(x);

    for (int i = (1 << 17); s.size() < n-3; i++) {
        s.insert(i);
        xsum ^= i;
    }

    s.insert((1<<18)|xsum);
    s.insert((1<<19)|(1<<18));
    s.insert((1<<19));

    print();

    return 0;
}
