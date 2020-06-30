#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, d, h, a, j;

    for (cin >> t; t > 0; t--){
        cin >> n >> d;
        cin >> a;
        for (int i = 1; i < n; i++){
            cin >> h;
            for (j = h; d < i*j; j--);
            if (j > 0){
                a += j;
                d -= i*j;
            }
        }
        cout << a << endl;
    }
    return 0;
}