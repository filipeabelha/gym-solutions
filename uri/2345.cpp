#include <bits/stdc++.h>
using namespace std;

int v[10];

int main () {
    scanf("%d%d%d%d", &v[0], &v[1], &v[2], &v[3]);
    sort(v,v+4);
    printf("%d\n", abs(v[3]+v[0]-v[1]-v[2]));
    return 0;
}
