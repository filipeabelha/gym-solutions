#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        vector <int> num1;
        vector <int> num2;
        while (1) {
            char chrr;
            scanf("%c", &chrr);
            if (chrr == 32)
                break;
            else {
                chr = chrr;
                num1.push_back(chr);
            }
        }
        while (1) {
            char chrr;
            scanf("%c", &chrr);
            if (chrr == 10)
                break;
            else {
                chr = chrr;
                num2.push_back(chr);
            }
        }
        int equal = 1;
        for (int j = 0; j < num2.size(); j++) {
            if (num2.size() > num1.size()) {
                equal = 0;
                break;
            }
            int diff = num1.size() - num2.size() + j;
            if (num2[j] != num1[diff])
                equal = 0;
        }
        if (equal)
            printf("encaixa\n");
        else
            printf("nao encaixa\n");
    }
    return 0;
}
