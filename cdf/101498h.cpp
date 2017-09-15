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
const int N = 1e6+5;

int t, n, s;

int main () {
    scanf("%d", &t);
    while (t--) {

        scanf("%d%d", &n, &s);

        int nin = (s/9)/2;
        int ext = -1;
        int zer = 0;
        int mid = -1;
        int err = 0;

        if (n%2 == 0 and s&1) err = 1;
        if (9*n < s) err = 1;
        if (s < 2 and n > 1) err = 1;

        if (err) printf("-1"); else {

            for (int i = 0; i < nin; i++) s -= 18, n -= 2;
            if (n > 1) ext = s/2, n -= 2, s -= 2*ext;
            while (n > 1) zer++, n -= 2;
            if (n) mid = s;

            for (int i = 0; i < nin; i++) printf("9");
            if (ext > -1) printf("%d", ext);
            for (int i = 0; i < zer; i++) printf("0");
            if (mid > -1) printf("%d", mid);
            for (int i = 0; i < zer; i++) printf("0");
            if (ext > -1) printf("%d", ext);
            for (int i = 0; i < nin; i++) printf("9");

        }


        printf("\n");
    }
    return 0;
}
