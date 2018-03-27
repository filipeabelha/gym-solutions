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
#define gcd(x, y) __gcd((x), (y))

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
const int N = 1e2+5;

string s, t;
int cnt, memo[N][N];
pii ind[N][N], par[N][N];

int dp (int i, int j) {
    if (~memo[i][j]) return memo[i][j];
    if (!i or !j) return memo[i][j] = 0;
    if (s[i-1] == t[j-1]) {
        par[i][j] = {i-1, j-1};
        ind[i][j] = {i-1, j-1};
        return memo[i][j] = 1 + dp(i-1, j-1);
    }
    if (dp(i-1, j) > dp(i, j-1)) {
        par[i][j] = {i-1, j};
        return memo[i][j] = dp(i-1, j);
    } else {
        par[i][j] = {i, j-1};
        return memo[i][j] = dp(i, j-1);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> s and s != "#" and ++cnt) {
        cl(memo, -1);
        cl(ind, -1);
        cl(par, 0);

        cin >> t;
        printf("Teste %d\n", cnt);

        if (t.size() > s.size()) swap(s, t);

        int n = s.size();
        int m = t.size();

        vector <pii> lcs;
        int x = dp(n, m);
        int i = n;
        int j = m;
        while (i and j) {
            int a = i;
            int b = j;
            if (~ind[a][b].st) lcs.pb(ind[a][b]);
            i = par[a][b].st;
            j = par[a][b].nd;
        }
        reverse(lcs.begin(), lcs.end());

        i = 0;
        j = 0;
        for (int k = 0; k < lcs.size(); k++) {
            while (i < lcs[k].st) printf("%c", s[i]), i++;
            while (j < lcs[k].nd) printf("%c", t[j]), j++;
            printf("%c", s[i]), i++, j++;
        }
        while (i < n) printf("%c", s[i]), i++;
        while (j < m) printf("%c", t[j]), j++;
        printf("\n\n");
    }
    return 0;
}
