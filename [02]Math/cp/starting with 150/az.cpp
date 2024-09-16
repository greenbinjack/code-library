#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k, arr[12], sum=0, flower=0;;
    cin >> k;
    for(int i=0;i<12;i++) cin >> arr[i];
    sort(arr, arr + 12);
    if(k == 0) cout << 0 << endl;
    else{
        for(int i=11;i>=0;i--) {
            sum += arr[i];
            flower++;
            if(sum >= k) break;
        }
        if(sum < k) cout << -1 << endl;
        else cout << flower << endl;
    }
    return 0;
}

