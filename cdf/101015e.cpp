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
 
const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

int n, p;
char a[100][52], b[100][52];

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf(" %s %s", b[i], a[i]);
    for (int i = 0, j; i < n; i++) {
        for (j = 0; j < n; j++)
            if (!strcmp(a[i], b[j])) break;
        if (j == n) {p = i; break;}
    }
    for (int cont = 0; cont < n; ) {
        printf("%s\n", a[p]); cont++;
        for (int i = 0; i < n; i++)
            if (!strcmp(b[p], a[i])) {p = i; break;};
    }
    printf("%s\n", b[p]);
    return 0;
}
