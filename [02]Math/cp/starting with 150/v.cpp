#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0, used, temp;
    cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	for(int i=0;i<n;i++){
		temp = arr[i];
		used = 0;
		if(arr[i] > 0){
			for(int j=0;j<n;j++){
				if(arr[j] > 0 && arr[j] % temp == 0) {
                    used = 1;
                    arr[j] = 0;
				}
			}
			if(used == 1) ans++;
        }
	}
	cout << ans << endl;
    return 0;
}


