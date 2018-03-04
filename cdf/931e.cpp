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
ld ans, p[30];
vi pos[30];
int cnt[30], f[30];

int main () {
    cin >> s;
    int n = s.size();
    s = s+s;
    for (int i = 0; i < n; i++) {
        int c = s[i]-'a';
        pos[c].pb(i);
        f[c]++;
    }
    for (int c = 0; c < 26; c++) {
        if (!f[c]) continue;
        for (int k = 1; k < n; k++) {
            cl(cnt, 0);
            int a = 0;
            int b = 0;
            for (auto i : pos[c]) {
                cnt[s[i+k]-'a']++;
                b++;
            }
            for (int j = 0; j < 30; j++) if (cnt[j] == 1) a++;
            if (b) p[c] = max(p[c], a/(ld)b);
        }
    }

    for (int i = 0; i < n; i++) {
        int c = s[i]-'a';
        ans += p[c]/n;
    }
    printf("%.10Lf\n", ans);
    return 0;
}
