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

vi u, v;
int ans;

void chk (int x) {
    int ok = 1;
    for (int i = 1; i <= 21; i += 4) {
        if (v[i]   != v[i+1]) ok = 0;
        if (v[i]   != v[i+2]) ok = 0;
        if (v[i]   != v[i+3]) ok = 0;
        if (v[i+1] != v[i+2]) ok = 0;
        if (v[i+1] != v[i+3]) ok = 0;
        if (v[i+2] != v[i+3]) ok = 0;
    }
    if (ok) {
        ans = 1;
        //db(x);
    }
}

int main () {
    u.pb(0);
    for (int i = 1; i <= 24; i++) u.pb(0), scanf("%d", &u[i]);

    // face 1
    v = u;
    swap(v[5], v[17]); swap(v[6], v[18]);
    swap(v[17], v[21]); swap(v[18], v[22]);
    swap(v[21], v[13]); swap(v[22], v[14]);
    chk(1);

    v = u;
    swap(v[21], v[13]); swap(v[22], v[14]);
    swap(v[17], v[21]); swap(v[18], v[22]);
    swap(v[5], v[17]); swap(v[6], v[18]);
    chk(1);

    // face 5
    v = u;
    swap(v[14], v[9]); swap(v[16], v[10]);
    swap(v[9], v[19]); swap(v[10], v[17]);
    swap(v[19], v[4]); swap(v[17], v[3]);
    chk(5);

    v = u;
    swap(v[19], v[4]); swap(v[17], v[3]);
    swap(v[9], v[19]); swap(v[10], v[17]);
    swap(v[14], v[9]); swap(v[16], v[10]);
    chk(5);

    // face 9
    v = u;
    swap(v[15], v[7]); swap(v[16], v[8]);
    swap(v[7], v[19]); swap(v[8], v[20]);
    swap(v[19], v[23]); swap(v[20], v[24]);
    chk(9);

    v = u;
    swap(v[19], v[23]); swap(v[20], v[24]);
    swap(v[7], v[19]); swap(v[8], v[20]);
    swap(v[15], v[7]); swap(v[16], v[8]);
    chk(9);

    // face 13
    v = u;
    swap(v[1], v[5]); swap(v[3], v[7]);
    swap(v[5], v[9]); swap(v[7], v[11]);
    swap(v[9], v[22]); swap(v[11], v[24]);
    chk(13);

    v = u;
    swap(v[9], v[22]); swap(v[11], v[24]);
    swap(v[5], v[9]); swap(v[7], v[11]);
    swap(v[1], v[5]); swap(v[3], v[7]);
    chk(13);

    // face 17
    v = u;
    swap(v[6], v[10]); swap(v[8], v[12]);
    swap(v[10], v[23]); swap(v[12], v[21]);
    swap(v[23], v[2]); swap(v[21], v[4]);
    chk(17);

    v = u;
    swap(v[23], v[2]); swap(v[21], v[4]);
    swap(v[10], v[23]); swap(v[12], v[21]);
    swap(v[6], v[10]); swap(v[8], v[12]);
    chk(17);

    // face 21
    v = u;
    swap(v[18], v[10]); swap(v[20], v[12]);
    swap(v[10], v[24]); swap(v[12], v[22]);
    swap(v[24], v[2]); swap(v[22], v[4]);
    chk(21);

    v = u;
    swap(v[24], v[2]); swap(v[22], v[4]);
    swap(v[10], v[24]); swap(v[12], v[22]);
    swap(v[18], v[10]); swap(v[20], v[12]);
    chk(21);

    printf("%s\n", ans ? "YES" : "NO");
    return 0;
}
