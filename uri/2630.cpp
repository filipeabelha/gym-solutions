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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int t, a, b, c, ans, cnt;
char ss[N];

int main () {
    scanf("%d ", &t);
    while (t-- and ++cnt) {
        scanf("%s ", ss);
        scanf(" %d%d%d ", &a, &b, &c);
        if      (ss[1] == 'i') ans = min(a, min(b, c));
        else if (ss[1] == 'a') ans = max(a, max(b, c));
        else if (ss[1] == 'e') ans = (a+b+c)/3;
        else                   ans = (30*a+59*b+11*c)/100;
        printf("Caso #%d: %d\n", cnt, ans);
    }
    return 0;
}
