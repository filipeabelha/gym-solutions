#include <bits/stdc++.h>
using namespace std;

const int N = 1e2+5;
char n1[N], n2[N];
int s1, s2;

int sum (int x) {
    int ans = 0;
    if (x < 10) return x;
    while (x > 0) ans += x % 10, x /= 10;
    return sum(ans);
}

int main () {
    while (1) {
        scanf("%s%s", n1, n2); if (n1[0] == '0' and n2[0] == '0') break;
        s1 = s2 = 0;
        for (int i = 0; i < strlen(n1); i++) s1 += n1[i] - '0';
        for (int i = 0; i < strlen(n2); i++) s2 += n2[i] - '0';
        printf("%d\n", sum(s1) > sum(s2) ? 1 : sum(s1) < sum(s2) ? 2 : 0);
    }
    return 0;
}
