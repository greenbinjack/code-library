#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, arr[130], div1, div2;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr + n);
    div1 = arr[n - 1];
    for(int i=1;i*i<=div1;i++) {
        if(div1 % i == 0) {
            for(int j=0;j<n;j++) {
                if(arr[j] == i) {
                    arr[j] = 0;
                    break;
                }
            }
            for(int j=0;j<n;j++) {
                if(arr[j] == (div1 / i)) {
                    arr[j] = 0;
                    break;
                }
            }
        }
    }
    sort(arr, arr + n);
    div2 = arr[n - 1];
    cout << div1 << ' ' << div2 << endl;

    return 0;
}



