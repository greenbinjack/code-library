#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s, n, cnt = 0;
    cin >> s >> n;
	vector< pair<int, int> > arr(n);
	for(int i=0;i<n;i++) cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end());
	for(int i=0;i<n;i++) {
		if(s > arr[i].first){
			cnt++;
			s += arr[i].second;
		}
		else break;
	}
	if(cnt == n) cout << "YES" << endl;
	else cout << "NO" << endl;
    return 0;
}

