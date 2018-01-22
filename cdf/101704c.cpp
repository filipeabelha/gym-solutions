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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LMOD = 1011112131415161719ll;
const int N = 1e2+5;

char s1[N], s2[N];
int m[N][N], len1, len2;
vi u[N][N], v[N][N];

int lcs(){
    len1 = strlen(s1);
    len2 = strlen(s2);
    for(int i=1;i<=len1;i++)
        for(int j=1;j<=len2;j++)
            if(s1[i-1]==s2[j-1])
            {
                m[i][j] = 1 + m[i-1][j-1];

                u[i][j] = u[i-1][j-1];
                v[i][j] = v[i-1][j-1];

                u[i][j].pb(i-1);
                v[i][j].pb(j-1);
            }
            else {
                if (m[i][j-1] >= m[i-1][j]) {
                    m[i][j] = m[i][j-1];
                    u[i][j] = u[i][j-1];
                    v[i][j] = v[i][j-1];
                } else {
                    m[i][j] = m[i-1][j];
                    u[i][j] = u[i-1][j];
                    v[i][j] = v[i-1][j];
                }
            }
    return m[len1][len2];
}

int main () {

    scanf("%s %s",s1,s2);
    printf("%d\n",lcs());
    for (auto x : u[len1][len2]) printf("%d ", x+1); printf("\n");
    for (auto x : v[len1][len2]) printf("%d ", x+1); printf("\n");
    return 0;
}
