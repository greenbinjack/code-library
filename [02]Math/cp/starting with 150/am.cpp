#include<bits/stdc++.h>
using namespace std;

int main()
{
    int height, length; cin >> height >> length;
    cout << fixed << setprecision(12);
    cout << (double)(length * length - height * height) / (2.0 * height) << endl;

    return 0;
}
