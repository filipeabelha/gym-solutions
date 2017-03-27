#include <bits/stdc++.h>
using namespace std;

int main () {
    char chr;
    int brk = 0;
    while (1) {
        vector <int> word;
        while (1) {
            if (scanf("%c", &chr) == EOF) brk = 1;
            if (chr == 10) break;
            if      (chr == '1') chr = 96;
            else if (chr == '2') chr = '1';
            else if (chr == '3') chr = '2';
            else if (chr == '4') chr = '3';
            else if (chr == '5') chr = '4';
            else if (chr == '6') chr = '5';
            else if (chr == '7') chr = '6';
            else if (chr == '8') chr = '7';
            else if (chr == '9') chr = '8';
            else if (chr == '0') chr = '9';
            else if (chr == '-') chr = '0';
            else if (chr == '=') chr = '-';
            else if (chr == 'W') chr = 'Q';
            else if (chr == 'E') chr = 'W';
            else if (chr == 'R') chr = 'E';
            else if (chr == 'T') chr = 'R';
            else if (chr == 'Y') chr = 'T';
            else if (chr == 'U') chr = 'Y';
            else if (chr == 'I') chr = 'U';
            else if (chr == 'O') chr = 'I';
            else if (chr == 'P') chr = 'O';
            else if (chr == '[') chr = 'P';
            else if (chr == ']') chr = '[';
            else if (chr == 92) chr = ']';
            else if (chr == 'S') chr = 'A';
            else if (chr == 'D') chr = 'S';
            else if (chr == 'F') chr = 'D';
            else if (chr == 'G') chr = 'F';
            else if (chr == 'H') chr = 'G';
            else if (chr == 'J') chr = 'H';
            else if (chr == 'K') chr = 'J';
            else if (chr == 'L') chr = 'K';
            else if (chr == ';') chr = 'L';
            else if (chr == 39) chr = ';';
            else if (chr == 'X') chr = 'Z';
            else if (chr == 'C') chr = 'X';
            else if (chr == 'V') chr = 'C';
            else if (chr == 'B') chr = 'V';
            else if (chr == 'N') chr = 'B';
            else if (chr == 'M') chr = 'N';
            else if (chr == ',') chr = 'M';
            else if (chr == '.') chr = ',';
            else if (chr == '/') chr = '.';
            word.push_back(chr);
        }
        if (brk) break;
        for (int i = 0; i < word.size(); i++)
            printf("%c", word[i]);
        printf("\n");
    }
    return 0;
}
