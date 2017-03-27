#include <bits/stdc++.h>
using namespace std;

string msg;
int uns;
char chr;

int main () {
    getline(cin, msg);
    for (int i = 0; 1; i++) {
        chr = msg[i];
        if (chr == '\0') break;
        if (chr == '1') uns++;
    }
    cout << msg;
    printf("%d\n", (uns % 2 == 0) ? 0 : 1);
    return 0;
}
