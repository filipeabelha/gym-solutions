#include <bits/stdc++.h>
using namespace std;

int n;
char chr;
string num;
set <string> s;

int main () {
    while (~scanf("%d%c", &n, &chr)) {
        s.clear();
        while (n--) {
            getline(cin, num);
            s.insert(num);
        }
        for (set<string>::iterator it = s.begin(); it != s.end(); ++it)
            cout << *it << endl;
    }
    return 0;
}
