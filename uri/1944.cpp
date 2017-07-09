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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

vector <string> v;
int n, ans;
char foo, c;

int main () {
    scanf("%d%c", &n, &foo);
    v.pb("FACE");
    while (n--) {
        string s;
        for (int i = 0; i < 4; i++) {
            scanf("%c%c", &c, &foo);
            s.pb(c);
        }
        string ss = s;
        reverse(ss.begin(), ss.end());
        if (ss == v[v.size()-1]) {
            ans++;
            v.erase(v.begin()+v.size()-1);
            if (v.empty()) v.pb("FACE");
        }
        else v.pb(s);
    }
    printf("%d\n", ans);
    return 0;
}
