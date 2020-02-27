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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int t, n;
string s;
vi ans;

void pr () {
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i+1==n];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;

    while (t--) {
        cin >> n >> s;

        // Min LIS
        ans.clear(); ans.resize(n);
        int cur = n;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '<') {
                int j = i;
                while (j < s.size() and s[j] == '<') j++;
                for (int k = j; k >= i; k--) ans[k] = cur--;
                i = j;
            } else ans[i] = cur--;
        }
        if (!ans[n-1]) ans[n-1] = cur--;
        pr();

        // Max LIS
        ans.clear(); ans.resize(n);
        cur = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '>') {
                int j = i;
                while (j < s.size() and s[j] == '>') j++;
                for (int k = j; k >= i; k--) ans[k] = cur++;
                i = j;
            } else ans[i] = cur++;
        }
        if (!ans[n-1]) ans[n-1] = cur++;
        pr();
    }

    return 0;
}
