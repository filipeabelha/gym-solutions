#include <bits/stdc++.h>
using namespace std;

int main () {
    double o, b, i; scanf("%lf%lf%lf", &o, &b, &i);
    printf("%s\n", o<b&&o<i?"Otavio":b<o&&b<i?"Bruno":i<o&&i<b?"Ian":"Empate");
    return 0;
}
