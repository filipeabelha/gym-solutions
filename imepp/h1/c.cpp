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

int t, m[50][50];

int main () {
    scanf("%d", &t);
    while (t--) {
        cl(m, 0);

        for (int i = 1; i <= 9; i += 2)
            for (int j = 1; j <= i; j += 2)
                scanf("%d", &m[i][j]);

        for (int i = 8; i >= 1; i -= 2)
            for (int j = 1; j <= i; j++)
                m[i][j] = m[i+1][j] + m[i+1][j+1];

        for (int i = 1; i <= 9; i++)
            for (int j = 1; j <= i; j++)
                printf("%d%c", m[i][j], " \n"[j==i]);

    }
    return 0;
}
