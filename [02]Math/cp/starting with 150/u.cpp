#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, s1 = 0, s2 = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for(int i=0;i<n/2;i++) s1 += arr[i];
    for(int i=n/2;i<n;i++) s2 += arr[i];
    cout << s1 * s1 + s2 * s2 << endl;

    return 0;
}

