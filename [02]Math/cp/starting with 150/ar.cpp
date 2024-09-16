#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, cnt = 1, mx = 1;
    cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin >> arr[i];
	for(int i=0;i+1<n;i++) {
		if(arr[i] <= arr[i+1]) cnt++;
		else cnt = 1;
		mx = max(mx, cnt);
	}
	mx = max(mx, cnt);
	cout << mx << endl;
    return 0;
}



