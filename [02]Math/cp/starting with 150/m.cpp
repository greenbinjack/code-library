#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, se, di, i, j, cnt;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    se = di = i = cnt = 0;
    j = n - 1;
	while(i <= j){
		if(cnt % 2 == 1){
			if(arr[i] >= arr[j]) {
                di += arr[i];
                i++;
			}
			else {
                di += arr[j];
                j--;
			}
		}
		else{
			if(arr[i] >= arr[j]) {
                se += arr[i];
                i++;
			}
			else {
                se += arr[j];
                j--;
			}
		}
		cnt++;
	}
	cout << se << " " << di << endl;
    return 0;
}



