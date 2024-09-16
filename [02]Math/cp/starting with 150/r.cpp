#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y, mx = 0;
    cin >> n;
	for(int i=0;i<n;i++){
        cin >> x >> y;
		if(x + y > mx) mx = x + y;
	}
	cout << mx << endl;

    return 0;
}



