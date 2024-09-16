#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double t, h, a;
    cin >> n >> t >> a;
    vector< pair<double, int> > arr(n);
    for(int i=0;i<n;i++) {
        cin >> h;
        arr[i].first = abs(a - (t - 0.006 * h));
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
    cout << arr[0].second << endl;

    return 0;
}
