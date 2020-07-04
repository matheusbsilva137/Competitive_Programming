#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , i, car, ordem = 0;
    stack<int> s;

    cin >> n;
    while (n != 0){
        ordem = 0;
        for (i = 1; i <= n; i++){
            cin >> car;
            if (car == ordem + 1){
                ordem++;
            }else{
                while (!s.empty() && s.top() == ordem + 1){
                    s.pop();
                    ordem++;
                }
                if (car == ordem + 1) ordem++;
                else s.push(car);
            }
        }

        while (!s.empty() && s.top() == ordem + 1){
            s.pop();
            ordem++;
        }

        if (ordem == n) cout << "yes" << endl;
        else cout << "no" << endl;
        cin >> n;
    }
    return 0;
}