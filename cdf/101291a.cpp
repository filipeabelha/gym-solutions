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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 50+10;   // Maximum sequence length
int n, l[N], ans;
char s[N];

int lis () {
    ans = 0;
    for (int i = 0; i < n; i++)
        l[i] = 1;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (s[j] < s[i] and l[j] + 1 > l[i])
                l[i] = l[j] + 1;
    for (int i = 0; i < n; i++)
        if (l[i] > ans) ans = l[i];
    return ans;
}

int main () {
    scanf("%s", s);
    n = strlen(s);
    printf("%d\n", 26-lis());
    return 0;
}
