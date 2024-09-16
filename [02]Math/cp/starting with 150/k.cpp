#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
   	if(b > a) swap(a, b);
   	if(c > a) swap(a, c);
   	if(b < c) swap(b, c);
   	cout << a - c << endl;
    return 0;
}


