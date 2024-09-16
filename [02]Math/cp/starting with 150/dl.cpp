#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, m, temp, pos1, pos2;
    char ss;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n >> m;
        vector<int> arr(n);
        for(int j=0;j<n;j++) cin >> arr[j];
        for(int j=1;j<=m;j++) {
            cin >> ss;
            if(ss == 'S') {
                cin >> temp;
                for(int i=0;i<n;i++) arr[i] += temp;
            }
            else if(ss == 'M') {
                cin >> temp;
                for(int i=0;i<n;i++) arr[i] *= temp;
            }
            else if(ss == 'D') {
                cin >> temp;
                for(int i=0;i<n;i++) arr[i] /= temp;
            }
            else if(ss == 'P') {
                cin >> pos1 >> pos2;
                swap(arr[pos1], arr[pos2]);
            }
            else reverse(arr.begin(), arr.end());
        }
        cout << "Case " << i << ": " << endl;
        for(int j=0;j<n;j++) cout << arr[j] << ' ';
        cout << endl;
    }
    return 0;
}
