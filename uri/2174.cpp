#include <bits/stdc++.h>
using namespace std;

int n;
string st;
char chr;
set <string> s;

int main () {
    scanf("%d%c", &n, &chr);
    while (n--) getline(cin, st), s.insert(st);
    printf("Falta(m) %d pomekon(s).\n", 151 - ( (int) s.size() ) );
    return 0;
}
