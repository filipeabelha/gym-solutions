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

long double a, b, c;

int main () {
    while (~scanf("%Lf%Lf%Lf", &a, &b, &c)) {
        long double p = (a+b+c)/2;
        long double s = sqrt(p*(p-a)*(p-b)*(p-c));
        long double r = s/p;
        long double rr = a*b*c/(4*s);
        printf("%.4Lf %.4Lf %.4Lf\n", PI*rr*rr-s, s-PI*r*r, PI*r*r);
    }
    return 0;
}
