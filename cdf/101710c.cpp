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

char s[N];
int sz;
vi pi;

int main () {
    scanf("%s", s);
    sz = strlen(s);
    pi.pb(0);
    int k = 0;
    for (int i = 1; i < sz; i++) {
        while (k > 0 and s[i] != s[k]) k = pi[k-1];
        if (s[i] == s[k]) k++;
        pi.pb(k);
    }
    for (auto x : pi) printf("%d ", x);
    printf("\n");
    return 0;
}
close
