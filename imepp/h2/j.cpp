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
const int N = 1e5+5;

set <int> ans[10];
int v[20];
int cnt, t;
char c;

int main () {

    while (~scanf("%d", &t) and t and ++cnt) {
        printf("Teste %d\n", cnt);

        for (int i = 0; i < 6; i++) {
            ans[i].clear();
            for (int j = 0; j < 10; j++)
                ans[i].insert(j);
        }


        while (t--) {
            for (int i = 1; i <= 10; i++) scanf(" %d", &v[i]);
            for (int i = 0; i < 6; i++) {
                scanf(" %c", &c);
                set <int> s = ans[i];
                for (auto k : ans[i]) {
                    if (k != v[2*(c-'A'+1)] and k != v[2*(c-'A'+1)-1]) {
                        s.erase(k);
                    }
                }
                ans[i] = s;
            }
        }

        for (int i = 0; i < 6; i++) printf("%d ", *(ans[i].begin()));
        printf("\n\n");
    }


    return 0;
}
