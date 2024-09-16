#include<bits/stdc++.h>
using namespace std;

int arr[200005];

int main()
{
    int n, k, sum = 0;
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr + n);
    if(k >= n) cout << 0 << endl;
    else {
        for(int i=0;i+k<n;i++) sum += arr[i];
        cout << sum << endl;
    }
    return 0;
}

