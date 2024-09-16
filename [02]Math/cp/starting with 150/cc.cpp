#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, arr[15], sum = 0;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr + n);
    for(int i=0;i<n-1;i++) sum += arr[i];
    if(sum > arr[n - 1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}



