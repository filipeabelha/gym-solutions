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

int n;
string s, o;

int main () {
    scanf("%d", &n);
    while (n--) {
        cin >> s;
        vi ind;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'm') ind.pb(i+1);
        ind[1] -= ind[0];
        ind[1] -= 3;
        ind[0] -= 2;
        printf("k");
        for (int i = 0; i < ind[0]*ind[1]; i++) printf("a");
        printf("\n");
    }
    return 0;
}
