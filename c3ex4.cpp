#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, m, k;
    int q;

    cin >> q;

    while (q > 0){
        cin >> n >> m >> k;

        if (abs(n) > k || abs(m) > k) cout << "-1" << endl;
        else if (abs(n) == abs(m)){
            if (k == abs(n) || abs(n) % 2 ==  k % 2) cout << k << endl;
            else cout << k - 2 << endl;
        }else{
            if (abs(n) % 2 == abs(m) % 2){
                if (k % 2 == abs(n) % 2) cout << k << endl;
                else cout << k - 2 << endl;
            }else cout << k - 1 << endl;
        }

        q--;
    }
}