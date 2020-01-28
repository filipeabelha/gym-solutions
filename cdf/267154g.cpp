#include <bits/stdc++.h>
using namespace std;
 
typedef vector <int> vi;
 
vi a[2], b[2];
 
void pr () {
    vi u = a[0];
    vi v = a[1];
    printf("(%d %d %d) ",   u[0], u[1], u[2]);
    printf("(%d %d %d)\n", v[0], v[1], v[2]);
    return;
}
 
void move (int k0, int k1) {
    int d0 = 0;
    int d1 = 0;
 
    if (a[0][k0] < b[0][k0]) d0 = 1;
    if (a[0][k0] > b[0][k0]) d0 = -1;
 
    if (a[1][k1] < b[1][k1]) d1 = 1;
    if (a[1][k1] > b[1][k1]) d1 = -1;
 
    a[0][k0] += d0;
    a[1][k1] += d1;
 
    pr();
}
 
 
int main () {
    a[0].resize(3);
    a[1].resize(3);
 
    b[0].resize(3);
    b[1].resize(3);
 
    for (int i = 0; i < 2; i++)
        scanf("%d%d%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &b[i][0], &b[i][1], &b[i][2]);
 
    pr();
 
    if (a[0][2] == a[1][2]) a[0][2]++;
 
    pr();
 
    while (a[0][0] != b[0][0] or a[1][0] != b[1][0]) move(0, 0);
    while (a[0][1] != b[0][1] or a[1][1] != b[1][1]) move(1, 1);
 
    if (a[0][0] != a[1][0] or a[0][1] != a[1][1]) {
 
        while (a[0][2] != b[0][2] or a[1][2] != b[1][2]) move(2, 2);
 
    } else if (a[0][0] == a[1][0]) {
 
        a[0][0]++; pr();
        while (a[0][2] != b[0][2] or a[1][2] != b[1][2]) move(2, 2);
        a[0][0]--; pr();
 
    } else if (a[0][1] == a[1][1]) {
 
        a[0][1]++; pr();
        while (a[0][2] != b[0][2] or a[1][2] != b[1][2]) move(2, 2);
        a[0][1]--; pr();
 
    }
 
    return 0;
    
}
