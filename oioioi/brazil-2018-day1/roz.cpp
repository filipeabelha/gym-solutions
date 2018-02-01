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
const int N = 1e6+5;

int n, sz, u, v, sum, ans, ch;
char s[N];

vi ind[30];

int main () {
    scanf("%d %s", &n, s);
    sz = strlen(s);

    for (int i = 0; i < sz; i++) ind[s[i]-'a'].pb(i);

    for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) if (i != j and ind[i].size() and ind[j].size()) {
        u = v = sum = ch = 0;
        while (u < ind[i].size() or v < ind[j].size()) {
            if      (v >= ind[j].size())    sum += (s[ind[i][u]] == i+'a'), ch |= 1, u++;
            else if (u >= ind[i].size())    sum -= (s[ind[j][v]] == j+'a'), ch |= 2, v++;
            else if (ind[i][u] < ind[j][v]) sum += (s[ind[i][u]] == i+'a'), ch |= 1, u++;
            else                            sum -= (s[ind[j][v]] == j+'a'), ch |= 2, v++;
            if (sum < 0) sum = 0, ch = 0;
            if (ch == 3 and sum > ans) ans = sum;
        }

        sum = ch = 0;
        u = ind[i].size()-1;
        v = ind[j].size()-1;
        while (u >= 0 or v >= 0) {
            if      (v < 0)                 sum += (s[ind[i][u]] == i+'a'), ch |= 1, u--;
            else if (u < 0)                 sum -= (s[ind[j][v]] == j+'a'), ch |= 2, v--;
            else if (ind[i][u] > ind[j][v]) sum += (s[ind[i][u]] == i+'a'), ch |= 1, u--;
            else                            sum -= (s[ind[j][v]] == j+'a'), ch |= 2, v--;
            if (sum < 0) sum = 0, ch = 0;
            if (ch == 3 and sum > ans) ans = sum;
        }
    }
    printf("%d\n", ans);
    return 0;
}
