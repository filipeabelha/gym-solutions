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

ll exp (ll b, ll e, ll mod) {
    ll ans = 1;
    while (e) {
        if (e&1 ) ans = ans*b % mod;
        b = b*b % mod;
        e /= 2;
    }
    return ans;
}

char chr;
int x, y;

int main () {
    while (1) {
        scanf("%c", &chr);
        if (chr == '\n') break;
        else {
            x = y;
            y = chr - '0';
        }
    }
    printf("%lld\n", (1+exp(2,(10*x+y)%4,5)+exp(3,(10*x+y)%4,5)+exp(4,(10*x+y)%4,5))%5);
    return 0;
}
