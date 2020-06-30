#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    int q7 = 0, q4 = 0, qLN;
    bool isNL = true;

    cin >> n;
    while (n != 0){
        if (n % 10 == 7) q7++;
        else if (n % 10 == 4) q4++;
        n /= 10;
    }
    
    qLN = q7 + q4;
    if (qLN == 0) isNL = false;
    while (qLN != 0 && isNL){
        if (qLN % 10 != 7 && qLN % 10 != 4) isNL = false;
        qLN /= 10;
    }

    if (isNL) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}