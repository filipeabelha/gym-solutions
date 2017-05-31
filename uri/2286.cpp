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

int n, x, y, cnt;
char chr, s1[100], s2[100];

int main () {
    while (scanf("%d%c", &n, &chr) and n and ++cnt) {
        printf("Teste %d\n", cnt);
        scanf("%s%c%s%c", s1, &chr, s2, &chr);
        while (n--) {
            scanf("%d %d%c", &x, &y, &chr);
            printf("%s\n%s", (x+y)&1 ? s2 : s1, !n ? "\n" : "");
        }
    }
    return 0;
}
