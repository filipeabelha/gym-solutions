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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;
char s[N];

int main () {
    scanf("%d ", &n);
    while (n--) {
        scanf(" %s", s);
        int n = strlen(s);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ans += 2;
            if (s[i] == '2') ans += 5;
            if (s[i] == '3') ans += 5;
            if (s[i] == '4') ans += 4;
            if (s[i] == '5') ans += 5;
            if (s[i] == '6') ans += 6;
            if (s[i] == '7') ans += 3;
            if (s[i] == '8') ans += 7;
            if (s[i] == '9') ans += 6;
            if (s[i] == '0') ans += 6;
        }
        printf("%lld leds\n", ans);
    }
    return 0;
}
