#include <bits/stdc++.h>
using namespace std;

int n;
char s[100];

int main () {
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        if (strcmp(s, "Batmain") == 0) printf("N\n");
        else printf("Y\n");
    }
    return 0;
}
