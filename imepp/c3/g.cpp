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

pii v[20];
int u[20];
int n;
string ans;

int main () {
    scanf("%d", &n);

    for (int i = 1; i <= 9; i++) {
        scanf("%d", &v[i].st);
        v[i].nd = -i;
        u[i] = v[i].st;
    }

    sort(v+1, v+9+1);

    int a = -v[1].nd;
    int c = v[1].st;

    if (n - c < 0) printf("-1\n");
    else {
        while (n - c >= 0) {
            ans.pb(a+'0');
            n -= c;
        }
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 1; j <= 9; j++) {
                int x = ans[i]-'0';
                if (n-u[j]+u[x] >= 0) {
                    n = n-u[j]+u[x];
                    ans[i] = j+'0';
                }
            }
        }
        for (auto c : ans) printf("%c", c);
        printf("\n");
    }

    return 0;
}
