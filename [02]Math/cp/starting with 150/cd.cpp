#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, arr[105], mn = INT_MAX, sum1, sum2;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=1;i<n;i++) {
        sum1 = sum2 = 0;
        for(int j=0;j<i;j++) sum1 += arr[j];
        for(int j=i;j<n;j++) sum2 += arr[j];
        if(abs(sum1 - sum2) < mn) mn = abs(sum1 - sum2);
    }
    cout << mn << endl;
    return 0;
}
