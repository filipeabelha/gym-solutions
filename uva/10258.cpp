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
const int N = 1e2+5;

int ac[N][N], pe[N][N], t, con, pro, tim;
char ver;
vector <pii> ran(N);
set <int> cont;
priority_queue <piii> pq;
string s;

int main () {
    scanf("%d", &t);
    cin.ignore();
    getline(cin, s);
    while (t--) {
        for (int i = 0; i < N; i++) ran[i] = {0, 0};
        cont.clear();
        cl(ac, 0);
        cl(pe, 0);

        while (1) {
            getline(cin, s);
            if (s.size() < 5) break;
            sscanf(s.c_str(), " %d %d %d %c", &con, &pro, &tim, &ver);
            cont.insert(con);
            if (ver == 'I') pe[con][pro] += 20;
            if (ver == 'C' and !ac[con][pro]) {
                ac[con][pro] = 1;
                pe[con][pro] += tim;
                ran[con].st++;
                ran[con].nd += pe[con][pro];
            }
        }

        for (auto c : cont) pq.push({ran[c].st, {-ran[c].nd, -c}});
        while (pq.size()) {
            piii p = pq.top(); pq.pop();
            printf("%d %d %d\n", -p.nd.nd, p.st, -p.nd.st);
        }

        if (t) printf("\n");
    }
    return 0;
}
