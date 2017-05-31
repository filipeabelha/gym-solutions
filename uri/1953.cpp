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

int n, epr, ehd, other, x;
char chr, w[100];

int main () {
    while (~scanf("%d%c", &n, &chr)) {
        epr = ehd = other = 0;
        while (n--) {
            scanf("%d %s%c", &x, w, &chr);
            if (!strcmp(w, "EPR")) epr++;
            else if (!strcmp(w, "EHD")) ehd++;
            else other++;
        }
        printf("EPR: %d\nEHD: %d\nINTRUSOS: %d\n", epr, ehd, other);
    }
    return 0;
}
