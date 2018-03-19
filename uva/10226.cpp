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

int n, x;
map <string, int> m;
string s;

int main () {
    scanf("%d", &n);
    cin.ignore();
    getline(cin, s);
    while (n--) {
        m.clear();
        x = 0;
        while (1) {
            getline(cin, s);
            if (s == "") break;
            m[s]++;
            x++;
        }
        for (auto p : m) printf("%s %.4Lf\n", p.st.c_str(), (ld) 100.*p.nd/x);
        if (n) printf("\n");
    }
    return 0;
}
