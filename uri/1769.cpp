#include <bits/stdc++.h>
using namespace std;

int a1, a2, a3, a4, a5, a6, a7, a8, a9, b1, b2;
string s;

int main () {
    while (getline(cin, s)) {
        a1 = s[0]-48; a2 = s[1]-48; a3 = s[2]-48;
        a4 = s[4]-48; a5 = s[5]-48; a6 = s[6]-48;
        a7 = s[8]-48; a8 = s[9]-48; a9 = s[10]-48;
        b1 = s[12]-48; b2 = s[13]-48;
        int b_1 = 1*a1 + 2*a2 + 3*a3 + 4*a4 + 5*a5 + 6*a6 + 7*a7 + 8*a8 + 9*a9;
        b_1 %= 11; b_1 %= 10;
        int b_2 = 9*a1 + 8*a2 + 7*a3 + 6*a4 + 5*a5 + 4*a6 + 3*a7 + 2*a8 + 1*a9;
        b_2 %= 11; b_2 %= 10;
        if (b1 == b_1 and b2 == b_2) printf("CPF valido\n");
        else printf("CPF invalido\n");
    }
    return 0;
}

