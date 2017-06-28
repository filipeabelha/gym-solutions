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

int tc, da, ta, db, tb, hp;

int main () {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d%d%d%d", &da, &ta, &db, &tb, &hp);
        for (int t = 0; ; t++) {
            if (t % ta == 0) {
                hp -= da;
                if (hp <= 0) {
                    printf("Andre\n");
                    break;
                }
            }
            if (t % tb == 0) {
                hp -= db;
                if (hp <= 0) {
                    printf("Beto\n");
                    break;
                }
            }
        }
    }
    return 0;
}
