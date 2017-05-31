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

int n, x, cnt;

int main () {
    while (scanf("%d", &n) and n and ++cnt) {
        printf("Teste %d\n", cnt);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (x == i) printf("%d\n\n", x);
        }
    }
    return 0;
}
