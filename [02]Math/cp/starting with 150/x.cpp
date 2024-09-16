#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s[105];
    int n, m, ans = 0, arr[1005], cnt[5], mx;
    cin >> n >> m;
	for(int i=0;i<n;i++) cin >> s[i];
	for(int i=0;i<m;i++) cin >> arr[i];
	for(int j=0;j<m;j++){
        for(int i=0;i<5;i++) cnt[i] = 0;
		for(int i=0;i<n;i++) cnt[s[i][j] - 'A']++;
		mx = cnt[0];
		for(int i=1;i<5;i++) mx = max(mx, cnt[i]);
		ans += mx * arr[j];
	}
	cout << ans << endl;

    return 0;
}



