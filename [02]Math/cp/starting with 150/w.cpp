// #author: greenbinjack
// #id    : 220041224
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, r, mn, mx, sell;
    cin >> n >> m >> r;
	vector<int> s(n), b(m);
    for(int i=0;i<n;i++) cin >> s[i];
	for(int i=0;i<m;i++) cin >> b[i];
	mn = s[0];
	mx = b[0];
	for(int i=0;i<n;i++) {
        if(s[i] < mn) mn = s[i];
	}
	for(int i=0;i<m;i++) {
        if(b[i] > mx) mx = b[i];
	}
	sell = (r / mn) * mx + r % mn;
	if(r > sell) swap(r, sell);
	cout << sell << endl;
    return 0;
}

