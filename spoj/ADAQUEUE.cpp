#include <bits/stdc++.h>
using namespace std;

int n, x, mode = 1;
string s;
char op[50], chr;
deque <int> d;

int main () {
    scanf("%d%c", &n, &chr);
    while (n--) {
        getline(cin, s);
        sscanf(s.c_str(), "%s%c", op, &chr);
        if (op[0] == 'r') mode = 1-mode;
        else if (op[0] == 'p') {
            sscanf(s.c_str(), "%s%c%d", op, &chr, &x);
            if (mode) d.push_back(x);
            else d.push_front(x);
        } else if (op[0] == 't') {
            sscanf(s.c_str(), "%s%c%d", op, &chr, &x);
            if (mode) d.push_front(x);
            else d.push_back(x);
        } else if (op[0] == 'b') {
            if (d.empty()) printf("No job for Ada?\n");
            else if (mode) printf("%d\n", d.back()), d.pop_back();
            else printf("%d\n", d.front()), d.pop_front();
        } else if (op[0] == 'f') {
            if (d.empty()) printf("No job for Ada?\n");
            else if (mode) printf("%d\n", d.front()), d.pop_front();
            else printf("%d\n", d.back()), d.pop_back();
        }
    }
    return 0;
}
