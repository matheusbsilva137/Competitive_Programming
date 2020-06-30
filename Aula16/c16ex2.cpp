#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, m, n;

    for (cin >> t; t > 0; t--){
        cin >> n >> m;
        if (n % m == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}