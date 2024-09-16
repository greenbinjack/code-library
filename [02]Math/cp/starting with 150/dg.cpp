#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, p, q, arr[35], sum, pos;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n >> p >> q;
        for(int j=0;j<n;j++) cin >> arr[j];
        sort(arr, arr + n);
        sum = pos = 0;
        while(pos < n && p > 0 && sum + arr[pos] <= q) {
            sum += arr[pos];
            pos++;
            p--;
        }
        cout << "Case " << i << ": " << pos << endl;
    }
    return 0;
}
