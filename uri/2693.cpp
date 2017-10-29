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
const int N = 1e5+5;

int n, dis;
string s, dir;
int cnt;

pair <int, pair <string, string> > p[N];

int main () {
    while (~scanf("%d ", &n)) {
        cnt = 0;
        while (n--) {
            cin >> s >> dir >> dis;
            p[cnt++] = mp(dis, mp(dir, s));
        }
        sort(p, p+cnt);
        for (int i = 0; i < cnt; i++)
            printf("%s\n", p[i].nd.nd.c_str());
    }
    return 0;
}
