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
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1000;
const int N = 1e5+5;

struct matrix {
    int a, b, c, d;

    matrix () : a(0), b(0), c(0), d(0) {}
    matrix (int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}

    matrix operator * (matrix Z) {
        return matrix ((Z.a*a + Z.c*b) % MOD,
                       (Z.b*a + Z.d*b) % MOD,
                       (Z.a*c + Z.c*d) % MOD,
                       (Z.b*c + Z.d*d) % MOD);
    }
};

matrix fexp (matrix b, int e) {
    matrix ans = matrix(1, 0, 0, 1);
    while (e) {
        if (e&1) ans = ans*b;
        b = b*b;
        e >>= 1;
    }
    return ans;
}

string s;
int n, x;

int main () {
    cin >> n;
    while (n--) {
        cin >> s;
        reverse(s.begin(), s.end());

        x = 0;
        int k = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                x += k;
                x %= 1500;
            }
            k <<= 1;
            k %= 1500;
        }

        matrix m = fexp(matrix(1, 1, 1, 0), x);

        printf("%03d\n", m.b);
    }

    return 0;
}
