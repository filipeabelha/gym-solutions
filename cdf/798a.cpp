#include <bits/stdc++.h>
using namespace std;

char s[30];
int a, b;

int main () {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n/2; i++) {
        if (s[i] == s[n-i-1]) continue;
        if (a) b = 1;
        a = 1;
    }
    printf("%s\n", ((a and !b) or (!a and (n%2==1))) ? "YES" : "NO");
    return 0;
}
