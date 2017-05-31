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

int d1, m1, d2, m2, ans;

int cnt (int d, int m) {
    return d+(m-1)*30+(m>1)+(m>3)+(m>5)+(m>7)+(m>8)+(m>10)-2*(m>2);
}

int main () {
    scanf("%d%d%d%d", &d1, &m1, &d2, &m2);
    printf("%d\n", cnt(d2, m2)-cnt(d1, m1));
    return 0;
}
