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

int n, cnt, a, b, c;

int main () {
    while (~scanf("%d", &n) and n and ++cnt) {
        printf("Teste %d\n", cnt);
        a = n/50; n %= 50;
        b = n/10; n %= 10;
        c = n/5;  n %= 5;
        printf("%d %d %d %d\n\n", a, b, c, n);
    }
    return 0;
}
