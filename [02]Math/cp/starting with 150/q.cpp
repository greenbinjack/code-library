#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, n_, rem;
    cin >> n;
	if(n >= 0) cout << n << endl;
	else{
        rem = n % 10;
		n_ = n / 10;
		n = (n / 100) * 10 + rem;
		if(n_ > n) swap(n_, n);
		cout << n << endl;
	}
    return 0;
}


