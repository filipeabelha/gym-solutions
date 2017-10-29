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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int n, m;
char id[N], a, b;
string s;

int main () {
    scanf("%d%d ", &n, &m);
    for (int i = 0; i < N; i++) id[i] = i;
    while (n--) {
        scanf("%c %c ", &a, &b);
        id[b] = a;
        id[a] = b;
    }
    while (m--) {
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) s[i] = id[s[i]];
        printf("%s\n", s.c_str());
    }
    return 0;
}
