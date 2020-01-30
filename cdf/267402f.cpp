#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

string s, t;

bool checkParentheses () {
    int cur = 0;
    for (auto c : t) {
        if (c == '(') cur++;
        if (c == ')') cur--;
        if (cur < 0) return false;
    }
    if (cur > 0) return false;
    return true;
}

bool isLetter (char c) {
    return c >= 'a' and c <= 'z';
}

bool checkSymbols () {
    // symbols: ( ) a *
    for (int i = 1; i < t.size(); i++) {
        if (t[i-1] == '(' and t[i] == ')') return false;
        if (t[i-1] == '(' and t[i] == '*') return false;
        if (t[i-1] == ')' and t[i] == '(') return false;
        if (t[i-1] == ')' and t[i] == 'a') return false;
        if (t[i-1] == '*' and t[i] == '*') return false;
        if (t[i-1] == '*' and t[i] == ')') return false;
        if (t[i-1] == 'a' and t[i] == 'a') return false;
        if (t[i-1] == 'a' and t[i] == '(') return false;
    }
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    getline(cin, s);

    t += '(';
    for (auto c : s) {
        if (c == ' ') continue;
        else if (c == '+') t += '*';
        else if (c == '-') t += '*';
        else if (c == '*') t += '*';
        else if (c == '/') t += '*';
        else if (c == '%') t += '*';
        else if (isLetter(c)) t += 'a';
        else t += c;
    }
    t += ')';

    if (!checkParentheses() or !checkSymbols()) {
        cout << "error\n";
        return 0;
    }

    stack <char> q;
    for (auto c : t) {
        if (c == ')') {
            string p = "";
            while (1) {
                char d = q.top(); q.pop();
                if (d == '(') break;
                else p += d;
            }
            if (p != "a*a") {
                cout << "improper\n";
                return 0;
            } else q.push('a');
        } else q.push(c);
    }

    if (q.size() != 1 or q.top() != 'a') {
        cout << "improper\n";
        return 0;
    }

    cout << "proper\n";

    return 0;
}
