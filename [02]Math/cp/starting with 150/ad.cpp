#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, arr[105], flag;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n;
        for(int j=0;j<n;j++) cin >> arr[j];
        sort(arr, arr + n);
        flag = 1;
        for(int j=0;i+1<n;j++) {
            if(arr[j + 1] - arr[j] == 1) {
                cout << 2 << endl;
                flag = 0;
                break;
            }
        }
        if(flag) cout << 1 << endl;
    }
    return 0;
}



