#include <bits/stdc++.h>

using namespace std;

int main () {
    int brk = 0;
    while (1) {
        vector <int> letters;
        char chr;
        scanf("%c", &chr);
        if (chr < 97) chr += 32;
        letters.push_back(chr);
        int result = 0;
        int weAreInAFirstNow = 0;
        while (1) {
            if (scanf("%c", &chr) == EOF) brk = 1;
            if (chr == 10) break;
            if (brk) break;
            if (weAreInAFirstNow) {
                if (chr < 97) chr += 32;
                letters.push_back(chr);
                weAreInAFirstNow = 0;
            }
            if (chr == 32) weAreInAFirstNow = 1;
        }
        if (brk) break;
        for (int i = 0; i < letters.size()-2; i++)
            if (letters[i] == letters[i+1] and letters[i] == letters[i+2]) {
                letters.erase(letters.begin()+i, letters.begin()+i+1);
                i--;
            }
        for (int i = 0; i < letters.size()-1; i++)
            if (letters[i+1] == letters[i])
                result++;
        printf("%d\n", result);
    }
    return 0;
}
