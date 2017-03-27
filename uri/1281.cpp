#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        map <string, double> m;
        double total = 0;
        int x, y;
        scanf("%d", &x);
        for (int j = 0; j < x; j++) {
            char item[60];
            double preco;
            scanf("%s %lf", item, &preco);
            m[item] = preco;
        }
        scanf("%d", &y);
        for (int j = 0; j < y; j++) {
            char item[60];
            double quant;
            scanf("%s %lf", item, &quant);
            double preco = m.find(item)->second;
            total += preco*quant;
        }
        printf("R$ %.2lf\n", total);
    }
    return 0;
}
