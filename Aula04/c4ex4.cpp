#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, maiorInter = 0, l, r;
    
    cin >> n;
    int* x = new int[n];
    int* y = new int[n];
    pair<int,int>* p = new pair<int,int>[n];

    for (i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        p[i].first = x[i];
        p[i].second = y[i];
    }
    
    sort(x, x+n);
    sort(y, y+n);

    for(i = 0; i < n; i ++){
        if (x[n - 1] == p[i].first) l = x[n-2];
        else l = x[n-1];

        if (y[0] == p[i].second) r = y[1];
        else r = y[0];

        if (r - l > maiorInter) maiorInter = r - l;
    }

    cout << maiorInter << endl;
}
