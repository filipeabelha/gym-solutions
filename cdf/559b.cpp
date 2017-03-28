#include <bits/stdc++.h>

const int N = 2e5+11;
char s1[N], s2[N];

int chkstr(int x1, int x2, int n) {
    for (int i = 0; i < n; i++)
        if (s1[x1+i] != s2[x2+i])
            return 0;
    return 1;
}

int checkin (int x1, int x2, int n) {
    if (chkstr(x1, x2, n)) return 1;
    if (n % 2 == 1) return 0;
    if (checkin(x1, x2, n/2) and checkin(x1+n/2, x2+n/2, n/2))
        return 1;
    if (checkin(x1, x2+n/2, n/2) and checkin(x1+n/2, x2, n/2))
        return 1;
    return 0;
}

int main () {
    scanf("%s%s", s1, s2);
    int len = strlen(s1);
    if (checkin(0,0,len))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
