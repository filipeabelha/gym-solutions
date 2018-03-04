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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, v[N];
int mini = INF;
int a, b, c;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        mini = min(mini, v[i]);
    }
    for (int i = 0; i < n; i++) {
        if      (v[i] == mini)   a++;
        else if (v[i] == mini+1) b++;
        else                     c++;
    }

    sort(v, v+n);

    if (!c) printf("%d\n", n);
    else if (min(a,c) > b/2) {

        printf("%d\n", n-2*min(a,c));
        for (int i = 0; i < min(a,c); i++) v[i] = v[n-1-i] = mini+1;

    } else {
        printf("%d\n", n-2*(b/2));

        int k = b/2;
        for (int i = 0; i < n; i++)
            if (k and v[i] == mini+1 and v[i-1] == mini+1)
                v[i] = mini, v[i-1] = mini+2, k--;
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", v[i], " \n"[i+1==n]);
    return 0;
}
