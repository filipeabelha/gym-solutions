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
const int N = 1e3+5;

ll bin[N][N];
string s;
int k;

ll go (int x, int d) {
    ll ans = 0;

    if (d == k-1) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') continue;
            int z = s.size()-i-1;
            ans += bin[z][x-cnt];
            ans %= MOD;
            cnt++;
            if (cnt > x) break;
        }
        return ans + (cnt == x) - (k == 1);
    }

    string b = "";
    for (int i = 0; i < min(x, 10); i++) b.pb('1');
    for (int i = min(x,10); i < 10; i++) b.pb('0');
    do {
        if (b > "1111101000") continue;
        bitset <20> bt(b);
        if (x == 1 and bt.to_ullong() == 1) continue;
        ans += go(bt.to_ullong(), d+1);
        ans %= MOD;
    } while (prev_permutation(b.begin(), b.end()));

    return ans;
}

int main () {
    for (int i = 0; i <= 1000; i++) bin[i][0] = 1;
    for (int i = 1; i <= 1000; i++) for (int j = 1; j <= i; j++)
        bin[i][j] = (bin[i-1][j] + bin[i-1][j-1])%MOD;

    cin >> s >> k;

    if (k == 0 and (s.back() == '1' or s.size() > 1)) printf("1\n");
    else printf("%lld\n", go(1, 0));

    return 0;
}
