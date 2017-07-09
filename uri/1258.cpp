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

int n, cnt;
string nam, col, siz;
char c;
vector <pair<string, pair<int, string> > > v;

int main () {
    while (~scanf("%d%c", &n, &c) and n and ++cnt) {
        v.clear();
        if (cnt > 1) printf("\n");
        for (int i = 0; i < n; i++) {
            getline(cin, nam);
            cin >> col; scanf("%c", &c);
            cin >> siz; scanf("%c", &c);
            int sz;
            (siz == "P" ? sz = 1 : siz == "M" ? sz = 2 : sz = 3);
            v.pb(mp(col, mp(sz, nam)));
        }
        sort(v.begin(), v.end());
        for (auto p : v) {
            printf("%s ", p.st.c_str());
            printf("%s ", p.nd.st == 1 ? "P" : p.nd.st == 2 ? "M" : "G");
            printf("%s\n", p.nd.nd.c_str());
        }

    }
    return 0;
}
