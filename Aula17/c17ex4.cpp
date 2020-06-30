#include<bits/stdc++.h>
using namespace std;
long long int DP[5000];

int main(){
    long long int v;
    string s;
    
    cin >> s;
    while (s != "0"){
        DP[0] = 1;
        for (int i = 1; i < s.size(); i++){
            if (i-2 >= 0) v = DP[i-2];
            else v = 1;

            if (s[i] == '0') DP[i] = v;
            else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) DP[i] = DP[i-1] + v;
            else DP[i] = DP[i-1];
        }
        cout << DP[s.size() - 1] << endl;
        cin >> s;
    }
    return 0;
}