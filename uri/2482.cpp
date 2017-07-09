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

map <string, string> m;

int n;
char c;
string a, b;

int main () {
    scanf("%d%c", &n, &c);
    while (n--) {
        getline(cin, a);
        getline(cin, b);
        m[a] = b;
    }
    scanf("%d%c", &n, &c);
    while (n--) {
        getline(cin, a);
        getline(cin, b);
        printf("%s\n%s\n\n", a.c_str(), m[b].c_str());
    }
    return 0;
}
