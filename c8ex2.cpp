#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a = 1, b = 0, c, num = 1;

    cin >> n;
    if (n == 0) cout << "0 0 0" << endl;
    else{
        while (num != n){
            num = a + b;
            c = b;
            b = a;
            a = num;
        }
        cout << b << " " << c << " 0" << endl;
    }
    return 0;
}