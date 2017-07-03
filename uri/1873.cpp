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

set <pair <string, string> > r, s;
pair <string, string> p;
char a[50], b[50], c;
int n;

int main () {
    p.st = "tesoura", p.nd = "papel";
    r.insert(p); swap(p.st, p.nd); s.insert(p);
    p.st = "papel", p.nd = "pedra";
    r.insert(p); swap(p.st, p.nd); s.insert(p);
    p.st = "pedra", p.nd = "lagarto";
    r.insert(p); swap(p.st, p.nd); s.insert(p);
    p.st = "lagarto", p.nd = "spock";
    r.insert(p); swap(p.st, p.nd); s.insert(p);
    p.st = "spock", p.nd = "tesoura";
    r.insert(p); swap(p.st, p.nd); s.insert(p);
    p.st = "tesoura", p.nd = "lagarto";
    r.insert(p); swap(p.st, p.nd); s.insert(p);
    p.st = "lagarto", p.nd = "papel";
    r.insert(p); swap(p.st, p.nd); s.insert(p);
    p.st = "papel", p.nd = "spock";
    r.insert(p); swap(p.st, p.nd); s.insert(p);
    p.st = "spock", p.nd = "pedra";
    r.insert(p); swap(p.st, p.nd); s.insert(p);
    p.st = "pedra", p.nd = "tesoura";
    r.insert(p); swap(p.st, p.nd); s.insert(p);
    while (~scanf("%d", &n)) {
        while (n--) {
            scanf("%s%s%c", a, b, &c);
            p.st = a; p.nd = b;
            printf("%s\n", r.count(p) ? "rajesh" : s.count(p) ? "sheldon" : "empate");
        }
    }
    return 0;
}
