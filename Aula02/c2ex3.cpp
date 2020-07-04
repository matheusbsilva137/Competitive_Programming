#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    long int x, y, a, b, s;

    cin >> t;
    while(t > 0){
        s = 0;
        cin >> x;
        cin >> y;
        cin >> a;
        cin >> b;

        if ( (y - x) % (a + b) == 0) cout << (y-x)/(a+b) << endl;
        else cout << "-1" << endl;
        t--;
    }
}