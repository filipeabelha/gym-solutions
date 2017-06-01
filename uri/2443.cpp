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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int a, b, c, d, num, den;

int main () {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    den = b*d;
    num = a*d + c*b;
    printf("%lld %lld\n", num/gcd(num, den), den/gcd(num, den));
    return 0;
}
