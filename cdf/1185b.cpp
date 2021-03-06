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

string s, t;
int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--) {
        cin >> s >> t;
        int i = 0, j = 0;
        int a = s.size(), b = t.size();
        if (s[i] != t[j]) {
            cout << "NO" << endl;
            continue;
        }
        while (1) {
            while (i+1 < a and j+1 < b and s[i+1] == t[j+1]) {
                i++;
                j++;
            }
            while (j+1 < b and t[j+1] == t[j]) j++;
            if (i+1 == a and j+1 == b) {
                cout << "YES" << endl;
                break;
            }
            if (i+1 == a or j+1 == b) {
                cout << "NO" << endl;
                break;
            }
            if (s[i+1] != t[j+1]) {
                cout << "NO" << endl;
                break;
            }
        }
    }
    return 0;
}
