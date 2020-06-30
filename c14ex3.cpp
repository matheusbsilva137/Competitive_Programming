#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int, int>> v;
    int n, i, a, b, danger = 0;
    int minX, minY;
    bool yAxes = true;

    cin >> n;
    cin >> a >> b;
    minX = a;
    minY = b;
    for (i = 1; i <= n; i++){
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    
    a = minX;
    b = minY;
    for (i = 0; i < n - 1; i++){
        if (yAxes){
            //norte ou sul
            //norte e vai para o oeste ou sul e vai para o leste
            if ( (v.at(i).second - b > 0 && v.at(i+1).first - a < 0) 
            || (v.at(i).second - b < 0 && v.at(i+1).first - a > 0) ) danger++;
        }else{
            //leste ou oeste
            //leste e vai para o norte ou oeste e vai para o sul
            if ( (v.at(i).first - a > 0 && v.at(i+1).second - b > 0) 
            || (v.at(i).first - a < 0 && v.at(i+1).second - b < 0) ) danger++;
        }
        a = v.at(i).first;
        b = v.at(i).second;
        yAxes = !yAxes;
    }

    cout << danger << endl;

    return 0;
}