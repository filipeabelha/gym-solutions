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

int n, a, x;
double d = 1000;

int main () {
    scanf("%d%d", &n, &a);
    for (int i = 1; i < n-1; i++)
        if (abs(i*180.0/n-a) < d) d = abs(i*180.0/n-a), x = i+1;
    printf("1 %d %d\n", n, x);
}
