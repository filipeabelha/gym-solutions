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

int n, z, k, f, ans[2];
string s = "";

int query (string s) {
    int k;
    cout << "? " << s << endl << flush;
    cin >> k;
    return k;
}

int diff (int l, int r) {
    l--; r--;
    for (int i = l; i <= r; i++) s[i] = '0';
    int a = query(s);
    for (int i = l; i <= r; i++) s[i] = '1';
    return z-a;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) s.pb('1');
    z = query(s);

    s[0] = '0';
    k = query(s);
    s[0] = '1';

    ans[k > z] = 1;
    //db((k>z) _ ans[k>z]);

    int l = 2, m, r = n;
    while (l <= r) {
        m = (l+r)/2;
        //db(l _ m _ r);

        int d = diff(l,m);

        if (ans[1]) {
            if (d == m-l+1) {
                ans[0] = l;
                break;
            } else if (d == -(m-l+1)) {
                l = m+1;
                continue;
            } else r = m;
        }

        if (ans[0]) {
            if (d == -(m-l+1)) {
                ans[1] = l;
                break;
            } else if (d == m-l+1) {
                l = m+1;
                continue;
            } else r = m;
        }
    }

    cout << "! " << ans[0] << " " << ans[1] << "\n";


    return 0;
}
