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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int t, a, b, c, d, e, f;
char o;

int lcm (int x, int y) { return x*y/gcd(x,y); }

void sum () {
    e = a*d + c*b;
    f = b*d;
}

void diff () {
    e = a*d - c*b;
    f = b*d;
}

void mult () {
    e = a*c;
    f = b*d;
}

void divi () {
    e = a*d;
    f = b*c;
}

int main () {
    scanf("%d", &t);
    while (t--) {
        scanf(" %d / %d %c %d / %d", &a, &b, &o, &c, &d);
        if (b < 0) a *= -1, b *= -1;
        if (d < 0) c *= -1, d *= -1;
        if (o == '+') sum();
        if (o == '-') diff();
        if (o == '*') mult();
        if (o == '/') divi();
        printf("%d/%d = ", e, f);
        int g = gcd(abs(e), abs(f));
        e /= g;
        f /= g;
        printf("%d/%d\n", e, f);
    }
    return 0;
}
