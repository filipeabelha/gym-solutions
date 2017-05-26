#include <bits/stdc++.h>
using namespace std;

int main () {
    int x, a, b, c; scanf("%d%d%d%d", &x, &a, &b, &c);
    printf("%c\n", x>a||x>b||x>c ? 'N' : 'S');
    return 0;
}
