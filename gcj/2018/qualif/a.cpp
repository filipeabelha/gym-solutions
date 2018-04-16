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

int n, d;
string s;

bool chk () {
    ll ans = 0;
    ll pwr = 1;
    for (auto c : s) {
        if (c == 'S') ans += pwr;
        else pwr <<= 1;
    }
    return (ans <= d);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int t = 1; t <= n; t++) {
        cout << "Case #" << t << ": ";
        cin >> d >> s;
        int cnt = 0;
        while (!chk()) {
            int ok = 0;
            for (int i = s.size()-1; i > 0; i--) {
                if (s[i] == 'S' and s[i-1] == 'C') {
                    swap(s[i], s[i-1]);
                    cnt++;
                    ok = 1;
                    break;
                }
            }
            if (!ok) break;
        }
        if (!chk()) cout << "IMPOSSIBLE" << endl;
        else        cout << cnt << endl;
    }
    return 0;
}
