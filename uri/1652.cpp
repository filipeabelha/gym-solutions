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

int l, n;
char u[30], v[30], chr;
map <string, string> ir;

void analyze () {
    int s = strlen(u)-1;
    if (ir.count(u)) {
        printf("%s\n", ir[u].c_str());
        return;
    }
    if (u[s] == 'y' and u[s-1] != 'a' and u[s-1] != 'e'
        and u[s-1] != 'i' and u[s-1] != 'o' and u[s-1] != 'u') {
        u[s] = 'i';
        u[s+1] = 'e';
        u[s+2] = 's';
        u[s+3] = '\0';
    } else if (u[s] == 'o' or u[s] == 's' or u[s] == 'x') {
        u[s+1] = 'e';
        u[s+2] = 's';
        u[s+3] = '\0';
    } else if ((u[s-1] == 'c' or u[s-1] == 's') and u[s] == 'h') {
        u[s+1] = 'e';
        u[s+2] = 's';
        u[s+3] = '\0';
    } else {
        u[s+1] = 's';
        u[s+2] = '\0';
    }
    printf("%s\n", u);
}

int main () {
    scanf("%d %d%c", &l, &n, &chr);
    while (l--) scanf("%s %s%c", u, v, &chr), ir[u] = v;
    while (n--) {
        scanf("%s%c", u, &chr);
        analyze();
    }
    return 0;
}
