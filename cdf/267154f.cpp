#include <bits/stdc++.h>
using namespace std;
 
typedef long double ld;
 
const int N = 405;
 
int a, b;
ld dp[N][N];
 
int main () {
    for (int i = 1; i < N; i++) dp[1][i] = dp[i][1] = 0.5;
 
    for (int i = 2; i < N; i++) {
        for (int j = 2; j < N; j++) {
            dp[i][j] = 0.5 + 0.5*(dp[i-1][j-1] + dp[i][j-1]);
        }
    }
 
    scanf("%d%d", &a, &b);
    printf("%.7Lf\n", dp[a][b]);
    return 0;
}
