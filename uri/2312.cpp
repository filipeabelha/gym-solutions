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
typedef pair<piii, string> T;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 5e2+10;

int n, o, p, b, id;
vector <T> v;
char chr, w[100];

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d%c", w, &o, &p, &b, &chr);
        v.pb(mp(mp(-o,mp(-p,-b)),w));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        o = -v[i].st.st;
        p = -v[i].st.nd.st;
        b = -v[i].st.nd.nd;
        printf("%s %d %d %d\n", v[i].nd.c_str(), o, p, b);
    }
    return 0;
}
