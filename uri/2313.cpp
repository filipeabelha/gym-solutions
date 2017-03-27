#include <bits/stdc++.h>
using namespace std;

int x, x1, x2, x3;
priority_queue <int> pq;

int main () {
    for (int i = 0; i < 3; i++) {
        scanf("%d", &x);
        pq.push(x);
    }
    x1 = pq.top(); pq.pop();
    x2 = pq.top(); pq.pop();
    x3 = pq.top(); pq.pop();
    if (x1 >= x2 + x3) printf("Invalido\n");
    else {
        printf("Valido-");
        if (x1 == x2 and x1 == x3) printf("Equilatero\n");
        else if (x1 != x2 and x1 != x3 and x2 != x3) printf("Escaleno\n");
        else printf("Isoceles\n");
        printf("Retangulo: ");
        if (x1*x1 == x2*x2 + x3*x3) printf("S\n"); else printf("N\n");
    }
    return 0;

}
