// #author: greenbinjack
// #id    : 220041224
#include<bits/stdc++.h>
using namespace std;

int calc(int n)
{
    return n * (n - 1) / 2;
}

int main()
{
    int n, cnt = 0;
    string s;
    cin >> n;
	vector<int> row(n), column(n);
	for(int i=0;i<n;i++) {
	    cin >> s;
		for(int j=0;j<n;j++) {
			if(s[j] == 'C') {
				row[i]++;
				column[j]++;
			}
		}
	}
	for(int i=0;i<n;i++) {
		if(row[i]) cnt += calc(row[i]);
		if(column[i]) cnt += calc(column[i]);
	}
	cout << cnt << endl;

    return 0;
}


