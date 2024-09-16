#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int yearFirst = 0, monthFirst = 0, fi, se;
    cin >> s;
    fi = (s[0] - '0') * 10 + (s[1] - '0');
    se = (s[2] - '0') * 10 + (s[3] - '0');
    if(fi >= 1 && fi <= 12) monthFirst++;
    if(se >= 1 && se <= 12) yearFirst++;
    if(yearFirst == 1 && monthFirst == 1) cout << "AMBIGUOUS" << endl;
    else if(yearFirst == 1) cout << "YYMM" << endl;
    else if(monthFirst == 1) cout << "MMYY" << endl;
    else cout << "NA" << endl;

    return 0;
}



