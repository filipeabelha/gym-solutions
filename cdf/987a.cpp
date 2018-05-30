include <bits/stdc++.h>
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

int n;
int v[N];
string s;

int main () {
    cin >> n;
    while (n--) {
        cin >> s;
        if (s[0] == 'p') v[0] = 1;
        if (s[0] == 'g') v[1] = 1;
        if (s[0] == 'b') v[2] = 1;
        if (s[0] == 'o') v[3] = 1;
        if (s[0] == 'r') v[4] = 1;
        if (s[0] == 'y') v[5] = 1;
    }
    int ans = 0;
    for (int i = 0; i < 6; i++) if (!v[i]) ans++;

    printf("%d\n", ans);
    if (!v[0]) printf("Power\n");
    if (!v[1]) printf("Time\n");
    if (!v[2]) printf("Space\n");
    if (!v[3]) printf("Soul\n");
    if (!v[4]) printf("Reality\n");
    if (!v[5]) printf("Mind\n");
    return 0;
}
