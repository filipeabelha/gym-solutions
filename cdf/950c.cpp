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
const int N = 2e5+5;

string s;
vii z(N);
set <int> ev, od;
int cnt;
int ok = 1;

int main () {
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (ev.empty()) {
                z[cnt].pb(i+1);
                od.insert(cnt);
                cnt++;
            } else {
                int k = *ev.begin();
                z[k].pb(i+1);
                od.insert(k);
                ev.erase(k);
            }
        } else if (s[i] == '1') {
            if (od.size()) {
                int k = *od.begin();
                z[k].pb(i+1);
                ev.insert(k);
                od.erase(k);
            } else ok = 0;
        }
    }
    if (ev.size() or !ok) printf("-1\n");
    else {
        printf("%d\n", cnt);
        for (int j = 0; j < cnt; j++) {
            printf("%d ", (int) z[j].size());
            for (auto x : z[j]) printf("%d ", x);
            printf("\n");
        }
    }
    return 0;
}
