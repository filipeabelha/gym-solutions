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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

int n, ans;
char chr, w[30];
set <string> s;

int main () {
    scanf("%d%c", &n, &chr);
    for (int i = 0; i < n; i++) {
        scanf("%c ", &chr);
        if (chr == '+') ans++;
        scanf("%s%c", w, &chr);
        s.insert(w);
    }
    for (auto i : s) printf("%s\n", i.c_str());
    printf("Se comportaram: %d | Nao se comportaram: %d\n", ans, n-ans);
    return 0;
}
