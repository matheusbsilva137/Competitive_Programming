#include<bits/stdc++.h>
using namespace std;
int ocurr[9];

int main(){
    int k, i, n;
    char c;
    bool press = true;

    cin >> k;
    for (i = 0; i < 16 && press; i++){
        cin >> c;
        if (c != '.'){
            n = c - '0';
            if (++ocurr[n-1] > 2*k){
                cout << "NO" << endl;
                press = false;
            }
        }
    }

    if (press) cout << "YES" << endl;

    return 0;
}