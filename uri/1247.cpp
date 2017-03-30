#include <bits/stdc++.h>
using namespace std;

int d, vf, vg;
long double acs, atn;

int main () {
    while (~scanf("%d %d %d", &d, &vf, &vg)) {
        acs = acos((long double) vf/vg);
        atn = atan((long double) d/12);
        printf("%s\n", (acs >= atn) ? "S" : "N");
    }
    return 0;
}
