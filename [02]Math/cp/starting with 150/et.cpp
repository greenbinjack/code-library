#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, arr[105], ans = 0, flag = 1;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=1;i<n;i++) {
        if(arr[i] == 1) {
            if(arr[i - 1] == 3) ans += 4;
            else ans += 3;
        }
        else if(arr[i] == 2) {
            if(arr[i - 1] == 3) {
                flag = 0;
                break;
            }
            else {
                if(i > 1 && arr[i - 2] == 3) ans += 2;
                else ans += 3;
            }
        }
        else {
            if(arr[i - 1] == 2) {
                flag = 0;
                break;
            }
            else ans += 4;
        }
    }
    if(flag == 1) cout << "Finite" << endl << ans << endl;
    else cout << "Infinite" << endl;

    return 0;
}
