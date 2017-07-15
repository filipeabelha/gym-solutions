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
const int N = 20;

int c;
char ch, s[N];

int main () {
    while (~scanf("%s%c%d%c", s, &ch, &c, &ch)) {
        printf("$");
        for (int i = 0; i < strlen(s); i++) {
            printf("%c", s[i]);
            if ((strlen(s)-i-1) == 0)     continue;
            if ((strlen(s)-i-1) % 3 == 0) printf(",");
        }
        printf(".%02d\n", c);
    }
    return 0;
}
