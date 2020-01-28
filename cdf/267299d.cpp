#include <bits/stdc++.h>
using namespace std;
 
int a1, b1, a2, b2;
 
int e1, e2;
 
int main () {
    scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
    e1 += a1 + b1;
    e1 += a2 + b2;
 
    scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
    e2 += a1 + b1;
    e2 += a2 + b2;
 
    printf("%s\n", e1 == e2 ? "Tie" : e1 > e2 ? "Gunnar" : "Emma");
 
}
