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
const int N = 1e4+5;

string s;
priority_queue <pii> pq;
int n, x, t;

int main () {
    while (1) {
        getline(cin, s);
        if (s == "#") break;
        sscanf(s.c_str(), "%*s %d %d", &x, &t);
        for (int i = t; i < N; i += t) pq.push({-i, -x});
    }
    scanf("%d", &n);
    while (n--) {
        printf("%d\n", -pq.top().nd);
        pq.pop();
    }
    return 0;
}
