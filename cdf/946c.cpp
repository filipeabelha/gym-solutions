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

char s[N];
string t = "abcdefghijklmnopqrstuvwxyz";
int ok;

int main () {
    scanf("%s", s);
    int j = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] <= t[j]) {
            s[i] = t[j];
            j++;
        }
        if (j == 26) break;
    }
    if (j == 26) ok = 1;
    printf("%s\n", ok ? s : "-1");
    return 0;
}
