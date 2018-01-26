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

string n, a;
char u[N], v[N];

int main () {
    freopen("isharp.in", "r", stdin);
    freopen("isharp.out", "w", stdout);
    scanf(" %s", u);
    while (1) {
        n = "";
        a = "";
        scanf(" %s", v);
        int sz = strlen(v);
        int i = 0;
        while ((v[i] >= 'A' and v[i] <= 'Z') or (v[i] >= 'a' and v[i] <= 'z')) n.pb(v[i++]);
        for (; i < sz-1; i++) a.pb(v[i] == '[' ? ']' : v[i] == ']' ? '[' : v[i]);
        reverse(a.begin(), a.end());
        printf("%s%s %s;\n", u, a.c_str(), n.c_str());
        if (v[sz-1] == ';') break;

    }
    return 0;
}
