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
const int N = 5e2+5;

int r, c, ok = 1;
char t[N][N];

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};

int main () {
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf(" %c", &t[i][j]);
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (t[i][j] != 'S') continue;
            for (int k = 0; k < 4; k++) {
                int x = i+dx[k];
                int y = j+dy[k];
                if (x < 1 or x > r) continue;
                if (y < 1 or y > c) continue;
                if (t[x][y] == 'W') ok = 0;
                if (t[x][y] == '.') t[x][y] = 'D';
            }
        }
    }
    if (!ok) return printf("No\n"), 0;
    printf("Yes\n");
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            printf("%c", t[i][j]);
        }
        printf("\n");
    }
    return 0;
}
