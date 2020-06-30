#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, a, b;

    for (cin >> t; t > 0; t--){
        cin >> a >> b;
        if (a % b == 0) cout << 0 << endl;
        else if (a < b) cout << b - a << endl;
        else cout << b - a % b << endl;
    }
    return 0;
}