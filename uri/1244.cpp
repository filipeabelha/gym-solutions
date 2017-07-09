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

vector <string> v[N];
char s[N], c;
int n;

int main () {
    scanf("%d%c", &n, &c);
    while (n--) {
        for (int i = 0; i < N; i++) v[i].clear();

        while (1) {
            scanf("%s%c", s, &c);
            v[strlen(s)].pb(s);
            if (c == '\n') break;
        }

        int fst = 1;
        for (int i = N-1; i >= 0; i--) for (auto x : v[i])
            printf("%s%s", fst ? "" : " ", x.c_str()), fst = 0;

        printf("\n");
    }
    return 0;
}
