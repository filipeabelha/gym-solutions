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

map <char, int> f;
string s;
int cnt;
set <char> t;

int main () {
    cin >> s;
    for (auto c : s) {
        f[c]++;
        if (f[c] >= 2) t.insert(c);
    }

    int cnt = t.size();
    if (f.size() > 4) return printf("No\n"), 0;
    if (f.size() == 4) return printf("Yes\n"), 0;
    if (f.size() == 3) {
        if (cnt >= 1) return printf("Yes\n"), 0;
        return printf("No\n"), 0;
    }
    if (f.size() == 2) {
        if (cnt >= 2) return printf("Yes\n"), 0;
        return printf("No\n"), 0;
    }
    printf("No\n");
    return 0;
}
