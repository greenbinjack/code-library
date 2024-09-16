#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h, w, r[105] = {0}, c[105] = {0};
    char arr[105][105];
    cin >> h >> w;
    for(int i=1;i<=h;i++) {
        for(int j=1;j<=w;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == '.') {
                r[i]++;
                c[j]++;
            }
        }
    }
    for(int i=1;i<=h;i++) {
        if(r[i] < w) {
            for(int j=1;j<=w;j++) {
                if(c[j] < h) cout << arr[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
