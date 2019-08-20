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
const int INF = 0x3f3f3f3f;
const int N = 1e5+5;

string s, p;
int b[N], n, m;

void kmppre() {
    n = s.size();
    m = p.size();

    b[0] = -1;
    for (int i = 0, j = -1; i < m; b[++i] = ++j)
        while (j >= 0 and p[i] != p[j])
            j = b[j];
}

void kmp() {
    vi ans;

    for (int i = 0, j = 0; i < n;) {
        while (j >= 0 and s[i] != p[j]) j=b[j];
        i++, j++;
        if (j == m) {
            ans.pb(i-m+1);
            j = b[j];
        }
    }

    if (ans.size()) {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " \n"[i==ans.size()-1];
    } else cout << "Not Found" << endl;
}

int t;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> s >> p;
        kmppre();
        kmp();
        if (t) cout << endl;
    }

    return 0;
}
