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
const int N = 1e5+5;

char lin[N];
int n;

int main () {
    scanf("%d ", &n);
    while (n--) {
        int ok = 0;
        gets(lin);
        int l = strlen(lin);
        lin[l++] = ' ';
        for (int i = 1; i < l; i++) {
            if (lin[i-1] == ' ' and l%i == 0) {
                int subok = 1;
                for (int j = i; j <= l; j += i)
                    if (lin[j-1] != ' ') subok = 0;
                if (subok) ok = 1;
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
