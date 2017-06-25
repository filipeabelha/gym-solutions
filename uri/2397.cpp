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

int v[3];

int main () {
    scanf("%d%d%d", &v[0], &v[1], &v[2]);
    sort(v, v+3);
    if (v[2] >= v[0] + v[1])                     printf("n\n");
    else if (v[2]*v[2] == v[0]*v[0] + v[1]*v[1]) printf("r\n");
    else if (v[2]*v[2] > v[0]*v[0] + v[1]*v[1])  printf("o\n");
    else if (v[2]*v[2] < v[0]*v[0] + v[1]*v[1])  printf("a\n");
    return 0;
}
