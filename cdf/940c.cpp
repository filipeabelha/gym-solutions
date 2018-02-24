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

string s;
char c;
int n, k;

set <char> u;
vector <char> v;

int main () {
    scanf("%d%d", &n, &k);
    cin >> s;
    for (auto z : s) if (!u.count(z)) u.insert(z);
    for (auto z : u) v.pb(z);
    if (n >= k) for (int i = min((int)s.size()-1, k-1); i >= 0; i--) {
        int w;
        for (int z = 0; z < v.size(); z++) if (v[z] == s[i]) w = z;
        if (w < v.size()-1) {
            s[i] = v[w+1];
            break;
        } else s[i] = v[0];
    }
    for (int i = 0; i < min((int)s.size(), k); i++) printf("%c", s[i]);
    for (int i = n; i < k; i++) printf("%c", v[0]);
    printf("\n");
    return 0;
}
