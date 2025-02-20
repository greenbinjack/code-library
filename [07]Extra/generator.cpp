#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1E6;

mt19937 rng(12345); // Fixed seed
LL randomInt(LL low, LL high) {
    return rand () % (high - low + 1) + low;
}

string generateRandomString(int length) {
    string s = "";
    string alphanum = "ACGT";
    // string alphanum = "abcdefghijklmnopqrstuvwxyz0123456789"; // [0, 25] --> alphabet, [26, 35] --> digit
    for (int i = 0; i < length; ++i) {
        s += alphanum[randomInt(0, 3)];
    }
    return s;
}

vector<int> permutation(int n){
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    shuffle(p.begin(), p.end(), rng);
    return p;
}

int main() {
    int n = 100000;
    cout << n << '\n';
    for (int i = 0; i < n; i++) {  
        cout << randomInt (1, 100) << ' ' << randomInt (1, 100) << '\n';
    }

    return 0;
}
