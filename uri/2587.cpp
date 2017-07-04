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

int n;
char a[20], b[20], c[20];

int main () {
    scanf("%d", &n);
    while (n--) {
        scanf("%s%s%s", a, b, c);
        int ok = 0;
        vi ind;
        for (int i = 0; i < strlen(c); i++)
            if (c[i] == '_') ind.pb(i);
        if (a[ind[0]] == b[ind[1]] or a[ind[1]] == b[ind[0]]) ok = 1;
        printf("%s\n", ok ? "Y" : "N");
    }
    return 0;
}
