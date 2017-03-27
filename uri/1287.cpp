#include <bits/stdc++.h>
using namespace std;

string num, ovf = "2147483647";

int main () {
    while (getline(cin, num)) {
        int err = 0;

        for (int i = num.size()-1; i >= 0; i--) {
            if (num[i] == 'o' or num[i] == 'O') num[i] = '0';
            if (num[i] == 'l') num[i] = '1';
            if (num[i] == ' ' or num[i] == ',') num.erase(i,1);
            else if (num[i] < '0' or num[i] > '9') err = 1;
        }
        if (num.empty()) err = 1;

        if (!err) {
            for (int i = 0; i <= num.size(); i++) {
                if (num[i] != '0') {
                    for (int j = i-1; j >= 0; j--) {
                        num.erase(j,1);
                        if (num.empty()) num.append("0");
                    }
                    break;
                }
            }

            if (num.size() > ovf.size()) err = 1;
            if (num.size() == ovf.size()) {
                for (int i = 0; i < num.size(); i++) {
                    if (ovf[i] < num[i]) err = 1;
                    else if (ovf[i] > num[i]) err = 0;
                    else continue;
                    break;
                }
            }
        }

        cout << (err ? "error" : num) << endl;
    }
    return 0;
}
