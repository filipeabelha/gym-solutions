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
const int N = 1e3+5;

string s;
int f[N];
int cnt;
vector <pii> ans;

int main () {
    while (cin >> s and ++cnt) {
        printf("%s", cnt > 1 ? "\n" : "");
        cl(f, 0);
        ans.clear();
        for (int i = 0; i < s.size(); i++) f[s[i]]++;
        for (int i = 0; i < N; i++) if (f[i]) ans.pb(mp(f[i], -i));
        sort(ans.begin(), ans.end());
        for (auto p : ans) printf("%d %d\n", -p.nd, p.st);
    }
    return 0;
}
