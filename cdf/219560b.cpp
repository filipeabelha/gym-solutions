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

char s[100];

map <pii, int> vis;

int dx[] = {+0, +1, +0, -1};
int dy[] = {+1, +0, -1, +0};

void pr (int d) {
    if (d == 0) printf("NORTH\n");
    if (d == 1) printf("EAST\n");
    if (d == 2) printf("SOUTH\n");
    if (d == 3) printf("WEST\n");
    fflush(stdout);
}

void go (int x, int y) {
    vis[mp(x, y)] = 1;

    for (int i = 0; i < 4; i++) {
        if (vis[mp(x+dx[i], y+dy[i])]) continue;
        pr(i);
        scanf(" %s", s);
        if (s[0] == 'E') {
            go(x+dx[i], y+dy[i]);
            pr((i+2)%4);
            scanf(" %s", s);
        }
    }
}

int main () {
    go(0, 0);
    printf("DONE\n");
    fflush(stdout);
    return 0;
}
