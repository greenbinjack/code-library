#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int flag;
    char vowels[12] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    cin >> s;
	for(int i=0;i<s.size();i++) {
        flag = 0;
        for(int j=0;j<12;j++) {
            if(s[i] == vowels[j]) flag = 1;
        }
		if(flag == 0){
		    cout << '.';
			if(s[i] >= 'A' && s[i] <= 'Z') cout << char(s[i] - 'A'+'a');
			else cout << s[i];
		}
	}
    return 0;
}
