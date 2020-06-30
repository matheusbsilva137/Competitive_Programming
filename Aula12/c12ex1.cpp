#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    long int a, b;

    for (cin >> t; t > 0; t--){
        cin >> a >> b;
        if ( (a + b) % 2 == 0){
            if (a == b) cout << "Ok" << endl;
            else cout << (a+b)/2 << " " << (a+b)/2 << endl;
        }else{
            if (abs(a-b) == 1) cout << "Ok" << endl;
            else cout << (a+b)/2 << " " << (a+b) - (a+b)/2 << endl;
        }
    }
    return 0;
}