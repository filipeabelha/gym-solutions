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

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

int cnt;
double x, y;

int main () {
    while (scanf("%lf%lf", &x, &y) == 2 and ++cnt) {
        printf("Projeto %d:\n", cnt);
        printf("Percentual dos juros da aplicacao: ");
        printf("%.2lf %%\n\n", 100*(y-x)/x);
    }
    return 0;
}
