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
const int N = 1e2+5;

string na, op, ans;
set <string> namesyes, namesno;
char c;

int main () {
    while (cin >> na and na != "FIM") {
        cin >> op; scanf("%c", &c);
        if (op == "YES") {
            namesyes.insert(na);
            if (na.size() > ans.size()) ans = na;
        } else namesno.insert(na);

    }
    for (auto x : namesyes) printf("%s\n", x.c_str());
    for (auto x : namesno) printf("%s\n", x.c_str());
    printf("\nAmigo do Habay:\n%s\n", ans.c_str());
    return 0;
}
