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
int ans;
char st[100];

int main () {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
       scanf("%s", st);
       if (st[0] == 'I') ans += 20;
       if (st[0] == 'T') ans += 4;
       if (st[0] == 'C') ans += 6;
       if (st[0] == 'O') ans += 8;
       if (st[0] == 'D') ans += 12;
    }
    printf("%d\n", ans);
    return 0;
}
