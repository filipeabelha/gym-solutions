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

int h, m;

int main () {
    while (~scanf("%d:%d", &h, &m)) {
        printf(" ____________________________________________\n");
        printf("|                                            |\n");
        printf("|    ____________________________________    |_\n");
        printf("|   |                                    |   |_)\n");
        printf("|   |   8         4         2         1  |   |\n");
        printf("|   |                                    |   |\n");
        printf("|   |   %s         %s         %s         %s  |   |\n",
        h&(1<<3)?"o":" ",
        h&(1<<2)?"o":" ",
        h&(1<<1)?"o":" ",
        h&(1<<0)?"o":" ");
        printf("|   |                                    |   |\n");
        printf("|   |                                    |   |\n");
        printf("|   |   %s     %s     %s     %s     %s     %s  |   |\n",
        m&(1<<5)?"o":" ",
        m&(1<<4)?"o":" ",
        m&(1<<3)?"o":" ",
        m&(1<<2)?"o":" ",
        m&(1<<1)?"o":" ",
        m&(1<<0)?"o":" ");
        printf("|   |                                    |   |\n");
        printf("|   |   32    16    8     4     2     1  |   |_\n");
        printf("|   |____________________________________|   |_)\n");
        printf("|                                            |\n");
        printf("|____________________________________________|\n\n");
    }
    return 0;
}
