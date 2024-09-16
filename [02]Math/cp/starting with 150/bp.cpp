#include<bits/stdc++.h>
using namespace std;

int arr[100005];

int main()
{
    int n, k, mn = INT_MAX;
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr + n);
    for(int i=0;i+k-1<n;i++) {
        if(arr[i + k - 1] - arr[i] < mn) mn = arr[i + k - 1] - arr[i];
    }
    cout << mn << endl;
    return 0;
}
