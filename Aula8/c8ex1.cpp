#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, y, n, i;
    cin >> x >> y >> n;

    for (i = 1; i <= n; i++){
        if (i % x == 0 || i % y == 0){
            if (i % x == 0) cout << "Fizz";
            if (i % y == 0) cout << "Buzz"; 
        }else{
            cout << i;
        }
        cout << endl;
    }
    return 0;
}