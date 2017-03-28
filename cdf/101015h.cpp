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
 
const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

int in[10][200], n;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            char hpy[15];
            scanf("%s", hpy);
//            printf("%s\n", hpy);
            for (int k = 0; k < strlen(hpy); k++)
                in[j][hpy[k]]++;
/*            for (int a = 0; a < 6; a++) {
                for (int b = 65; b <= 76; b++)
                    printf("%d ", in[a][b]);
                printf("\n");
                
            }*/
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 195; j++) {
            if (in[i][j] == n)
                printf("%c", j);
        }
        printf(" ");
    }
    printf("\n");
    return 0;
}
