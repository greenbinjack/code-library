#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, cnt = 1;
    cin >> n >> m;
	if(m < n) swap(n, m);
	for(int i=2;i<=n;i++) cnt *= i;
	cout << cnt << endl;
    return 0;
}



