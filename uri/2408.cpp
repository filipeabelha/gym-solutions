#include <bits/stdc++.h>
using namespace std;

int v[5];

int main () {
    scanf("%d%d%d", &v[0], &v[1], &v[2]);
    sort(v,v+3);
    printf("%d\n", v[1]);
    return 0;
}
