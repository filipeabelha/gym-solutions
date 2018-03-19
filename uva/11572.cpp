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

int t, n, x, cnt, ans;
queue <int> q;
set <int> s;

int main () {
    scanf("%d", &t);
    while (t--) {
        while (q.size()) q.pop();
        s.clear();
        ans = 0;
        cnt = 0;

        scanf("%d", &n);
        while (n--) {
            scanf("%d", &x);
            if (!s.count(x)) {
                s.insert(x);
                q.push(x);
                cnt++;
            }
            else {
                while (s.count(x)) {
                    s.erase(q.front());
                    q.pop();
                    cnt--;
                }
                s.insert(x);
                q.push(x);
                cnt++;
            }
            ans = max(ans, cnt);

        }
        printf("%d\n", ans);
    }
    return 0;
}
