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

int tc;
char num[100], chr;

ll getNum() {
    ll ans = 0, cnt = 1;
    for (int i = strlen(num)-1; i >= 0; i--) {
        if (num[i] == '1') ans += cnt;
        cnt *= 2;
    }
    return ans;
}

int main () {
    scanf("%d%c", &tc, &chr);
    for (int i = 1; i <= tc; i++) {
        scanf("%s%c", num, &chr);
        ll a = getNum();
        scanf("%s%c", num, &chr);
        ll b = getNum();
        printf("Pair #%d: %s!\n", i, gcd(a,b)>1?"All you need is love":"Love is not all you need");
    }
    return 0;
}
