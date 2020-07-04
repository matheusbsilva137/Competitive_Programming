#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, k, i, h, pts = 0;
    bool jogou;
    cin >> n >> a >> b >> k;

    int* distEspec = new int[n];

    for(i = 0; i < n; i++){
        cin >> h;
        if (h % (a+b) <= a && h % (a+b) != 0 ) distEspec[i] = 0;
        else if (h % (a+b) == 0) distEspec[i] = b;
        else distEspec[i] = (h % (a + b)) - a;
    }

    sort(distEspec, distEspec + n);
    for(i = 0; i < n; i++){
        jogou = false;
        if (distEspec[i] == 0){
            pts++;
        }else if (k > 0){
            while (!jogou && k > 0){
                k--;
                distEspec[i] -= a;
                if (distEspec[i] <= 0){
                    jogou = true;
                    pts++;
                }
            }
        }
    }

    cout << pts << endl;
}
