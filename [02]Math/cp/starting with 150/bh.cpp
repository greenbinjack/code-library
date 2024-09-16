#include<bits/stdc++.h>
using namespace std;

int arr[150005];

int main()
{
    int tc, n, low, cnt;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n;
        for(int j=0;j<n;j++) cin >> arr[j];
        low = arr[n - 1], cnt = 0;
        for(int j=n-2;j>=0;j--) {
            if(arr[j] > low) cnt++;
            low = min(low, arr[j]);
        }
        cout << cnt << endl;
    }
    return 0;
}


