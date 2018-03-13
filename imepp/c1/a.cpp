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

int t;
string a[5], b[5], s[5];

void pr (char c, int op) {
    printf("%c is the counterfeit coin and it is %s.\n", c, op ? "light" : "heavy");
}

bool heavy (char c) {
    for (int i = 0; i < 3; i++) {
        int l = 0, r = 0;
        for (auto z : a[i]) l += 1 + 100*(c == z);
        for (auto z : b[i]) r += 1 + 100*(c == z);
        if (s[i][0] == 'e' and l != r) return false;
        if (s[i][0] == 'u' and l <= r) return false;
        if (s[i][0] == 'd' and l >= r) return false;
    }
    return true;
}

bool light (char c) {
    for (int i = 0; i < 3; i++) {
        int l = 0, r = 0;
        for (auto z : a[i]) l -= 1 + 100*(c == z);
        for (auto z : b[i]) r -= 1 + 100*(c == z);
        if (s[i][0] == 'e' and l != r) return false;
        if (s[i][0] == 'u' and l <= r) return false;
        if (s[i][0] == 'd' and l >= r) return false;
    }
    return true;
}

int main () {
    scanf("%d ", &t);
    while (t--) {
        for (int i = 0; i < 3; i++) cin >> a[i] >> b[i] >> s[i];
        for (char c = 'A'; c <= 'L'; c++) {
            if      (heavy(c)) { pr(c, 0); break; }
            else if (light(c)) { pr(c, 1); break; }
        }
    }
    return 0;
}
