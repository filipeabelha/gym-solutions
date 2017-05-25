#include <bits/stdc++.h>
using namespace std;

int n, qty, ltrsize;
char chr, ltr[10];
map <string, string> m;
string st;

int main () {
    m[".-"] = 'a'; m["-..."] = 'b'; m["-.-."] = 'c'; m["-.."] = 'd';
    m["."] = 'e'; m["..-."] = 'f'; m["--."] = 'g'; m["...."] = 'h';
    m[".."] = 'i'; m[".---"] = 'j'; m["-.-"] = 'k'; m[".-.."] = 'l';
    m["--"] = 'm'; m["-."] = 'n'; m["---"] = 'o'; m[".--."] = 'p';
    m["--.-"] = 'q'; m[".-."] = 'r'; m["..."] = 's'; m["-"] = 't';
    m["..-"] = 'u'; m["...-"] = 'v'; m[".--"] = 'w'; m["-..-"] = 'x';
    m["-.--"] = 'y'; m["--.."] = 'z';
    scanf("%d%c", &n, &chr); while (n--) {
        getline(cin, st); for (int i = 0; i < st.size(); i++) {
            if (st[i] == '=') qty++;
            if (st[i] == '.' or i == st.size()-1) {
                if (qty == 3) ltr[ltrsize++] = '-';
                else ltr[ltrsize++] = '.'; qty = 0;
                if (st[i+1] == '.' or i == st.size() - 1) {
                    ltr[ltrsize++] = '\0'; ltrsize = 0;
                    printf("%s", m[ltr].c_str());
                    if (st[i+1] == '.') {
                        i += 2;
                        if (st[i+1] == '.') printf(" "), i += 4;
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
