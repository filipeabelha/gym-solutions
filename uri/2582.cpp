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

int n, a, b;
char s[50];

int main () {
    scanf("%d", &n); while (n--) {
        scanf("%d%d", &a, &b);
        a += b;
        if (a == 0)  strcpy(s, "PROXYCITY");
        if (a == 1)  strcpy(s, "P.Y.N.G.");
        if (a == 2)  strcpy(s, "DNSUEY!");
        if (a == 3)  strcpy(s, "SERVERS");
        if (a == 4)  strcpy(s, "HOST!");
        if (a == 5)  strcpy(s, "CRIPTONIZE");
        if (a == 6)  strcpy(s, "OFFLINE DAY");
        if (a == 7)  strcpy(s, "SALT");
        if (a == 8)  strcpy(s, "ANSWER!");
        if (a == 9)  strcpy(s, "RAR?");
        if (a == 10) strcpy(s, "WIFI ANTENNAS");
        printf("%s\n", s);
    }
    return 0;
}
