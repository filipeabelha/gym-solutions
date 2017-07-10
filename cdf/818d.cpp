#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

int n, a, x, freq[N];

int main(){
    scanf("%d%d", &n, &a);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (freq[x] >= freq[a]) freq[x]++;
    }
    for (int i = 1; i <= 1e6; i++)
        if (i != a and freq[i] >= freq[a]) return 0*printf("%d\n", i);
    printf("-1\n");
    return 0;
}
