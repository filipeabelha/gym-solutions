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

string w;
int x;

int sum (int x) {
    int ans = 0;
    while (x > 0) ans += x%10, x /= 10;
    return ans < 10 ? ans : sum(ans);
}

int main () {
    while (getline(cin, w)) {
        x = 0;
        for (auto c : w) {
            if (c >= 'a' and c <= 'z')
                x += (c-'a'+1)%9 == 0 ? 9 : (c-'a'+1)%9;
            if (c >= 'A' and c <= 'Z')
                x += (c-'A'+1)%9 == 0 ? 9 : (c-'A'+1)%9;
        }
        printf("%d\n", sum(x));
    }
    return 0;
}
