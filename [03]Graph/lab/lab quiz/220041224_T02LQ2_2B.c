#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int N = 1025;

void sort(char *s, int n) {
    char temp;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(s[i] > s[j]) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    char str[N], lowercase[N], uppercase[N];
    int n, low = 0, up = 0;
    scanf("%s", str);
    n = strlen(str);

    for(int i = 0; i < n; i++) {
        if(str[i] == tolower(str[i])) lowercase[low++] = str[i];
        else uppercase[up++] = str[i];
    }
    lowercase[low] = '\0';
    uppercase[up] = '\0';

    sort(lowercase, low);
    sort(uppercase, up);

    low = 0, up = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == tolower(str[i])) str[i] = lowercase[low++];
        else str[i] = uppercase[up++];
    }

    printf("%s\n", str);

    return 0;
}
