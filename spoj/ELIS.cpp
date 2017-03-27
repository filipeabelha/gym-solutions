#include <bits/stdc++.h>
using namespace std;

int n, s[20], l[20], ans;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        l[i] = 1, scanf("%d", &s[i]);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (s[j] < s[i] and l[j] + 1 > l[i])
                l[i] = l[j] + 1;
    for (int i = 0; i < n; i++)
        if (l[i] > ans) ans = l[i];
    printf("%d\n", ans);
    return 0;
}
