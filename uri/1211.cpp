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

int n, ans;
string s;
vector <string> v;
char chr;

int main () {
    while (~scanf("%d%c", &n, &chr) and n) {
        v.clear();
        ans = 0;
        while (n--) {
            getline(cin, s);
            v.pb(s);
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                if (v[i][j] == v[i-1][j]) ans++;
                else break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
