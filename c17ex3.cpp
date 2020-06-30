#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
int DP[MAX][MAX];
string a, b;

int lcsLen(int i, int j){
    if (i == 0 || j == 0) DP[i][j] = 0;
    else if (DP[i][j] == -1){
        if (a.at(i-1) == b.at(j-1)) DP[i][j] = lcsLen(i - 1, j - 1) + 1;
        else DP[i][j] = max(lcsLen(i-1, j), lcsLen (i, j-1));
    }
    return DP[i][j];
}

int main(){
    while (getline(cin, a)){
        getline(cin, b);
        for (int i = 1; i <= a.length(); i++)
            for (int j = 1; j <= b.length(); j++) DP[i][j] = -1;
        
        cout << lcsLen(a.length(), b.length()) << endl;
    }
    return 0;
}