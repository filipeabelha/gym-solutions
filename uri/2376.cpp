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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 20;

int h[N], v[N], w[N];

int main () {
    for (int i = 1; i <= 15; i++) scanf("%d%d", &h[i], &v[i]);
    for (int i = 1; i <= 8; i++) {if (h[i] > v[i]) w[i] = 2*i; else w[i] = 2*i+1;}
    if (h[9] > v[9]) w[9] = w[1]; else w[9] = w[2];
    if (h[10] > v[10]) w[10] = w[3]; else w[10] = w[4];
    if (h[11] > v[11]) w[11] = w[5]; else w[11] = w[6];
    if (h[12] > v[12]) w[12] = w[7]; else w[12] = w[8];
    if (h[13] > v[13]) w[13] = w[9]; else w[13] = w[10];
    if (h[14] > v[14]) w[14] = w[11]; else w[14] = w[12];
    if (h[15] > v[15]) w[15] = w[13]; else w[15] = w[14];
    printf("%c\n", w[15]+'A'-2);
    return 0;
}
