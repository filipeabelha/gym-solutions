#include <bits/stdc++.h>
using namespace std;
 
const int N = 15;
int n, ans = 0x3f3f3f3f;
vector <int> v;
 
int main () {
    scanf("%d", &n);
    v.resize(n+1);
 
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
        
    sort(v.begin(), v.end());
 
    for (int i = 1; i <= n; i++) {
        ans = min(ans, (n-i+1)+v[i-1]);
    }
 
    printf("%d\n", ans);
 
    return 0;
}
