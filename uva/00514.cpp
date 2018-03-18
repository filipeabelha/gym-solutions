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
const int N = 1e5+5;

int n, x, cnt, t[N];
stack <int> s;

void getFromStack () {
    while (s.size() and s.top() == t[cnt]) {
        s.pop();
        cnt++;
        continue;
    }
}

int main () {
    while (~scanf("%d", &n) and n) {
        while (1) {
            while (s.size()) s.pop();
            cnt = 1;

            for (int i = 1; i <= n; i++) {
                scanf("%d", &t[i]);
                if (i == 1 and t[1] == 0) goto END;
            }

            for (int i = 1; i <= n; i++) {
                if (i == t[cnt]) {
                    cnt++;
                    continue;
                }
                getFromStack();
                s.push(i);
            }

            getFromStack();
            printf("%s\n", s.size() ? "No" : "Yes");
        }
END:
        printf("\n");
    }
    return 0;
}
