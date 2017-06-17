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

int n, x, ans, cnt;
char chr;

int main () {
    scanf("%d", &n);
    while (1) {
        ans = 0;
        while (++ans) {
            chr = cnt = 0;
            while (chr != '\n' and ++cnt)
                scanf("%d%c", &x, &chr);
            if (cnt == 1) {
                printf("%d\n", ans-1);
                n = x;
                while (n == 1) {
                    scanf("%d%d", &x, &n);
                    printf("1\n");
                }
                break;
            }
        }
        if (!n) break;
    }
    return 0;
}
