#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
	vector< pair<int, int> > arr(n);
	for(int i=0;i<n;i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
	}
	sort(arr.begin(), arr.end());
	for(int i=0, j=n-1;i<n/2;i++, j--) {
		cout << arr[i].second << ' ' << arr[j].second << endl;
	}
	return 0;
}

