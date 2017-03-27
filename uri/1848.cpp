#include <bits/stdc++.h>
using namespace std;

int sum, caws;
string line;

int main () {
    while (1) {
        getline(cin, line);
        if (line[0] == 'c') {
            caws++;
            printf("%d\n", sum);
            sum = 0;
        }
        if (caws == 3) return 0;
        if (line[0] == '*') sum += 4;
        if (line[1] == '*') sum += 2;
        if (line[2] == '*') sum += 1;
    }
}
