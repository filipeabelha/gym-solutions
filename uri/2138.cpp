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

char n[1100];
int freq[10], maxi, ans;

int main () {
    while(~scanf("%s", n)) {
        maxi = ans = 0;
        cl(freq, 0);
        for (int i = 0; i < strlen(n); i++) {
            int x = n[i]-'0';
            freq[x]++;
            if (freq[x] > maxi) maxi = freq[x], ans = x;
            if (freq[x] == maxi) ans = max(ans, x);
        }
        printf("%d\n", ans);
    }
    return 0;
}
