#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;

    int ans = 0;
    for (char c = 'z'; c > 'a'; c--) {
        while (1) {
            int ok = 0;
            for (int i = 0; i < s.size(); i++) {
                int j = i-1;
                int k = i+1;
                while (j >= 0 and s[j] == 0) j--;
                while (k < s.size() and s[k] == 0) k++;
                if (s[i] == c and ((j >= 0 and s[j] == c-1) or
                                   (k < s.size() and s[k] == c-1))) {
                    ans++;
                    s[i] = 0;
                    ok = 1;
                }
            }
            if (!ok) break;
        }
    }

    cout << ans << "\n";

    return 0;
}
