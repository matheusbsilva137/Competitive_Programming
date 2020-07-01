#include<bits/stdc++.h>
using namespace std;

int main(){
    int d, sumTime, min, max, smax = 0, smin = 0, comp = 0;
    vector<pair<int, int>> m;
    
    cin >> d >> sumTime;

    for (int i = 0; i < d; i++){
        cin >> min >> max;
        smax += max;
        smin += min;
        m.push_back(make_pair(min, max));
    }

    if (smax < sumTime || smin > sumTime) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        comp = sumTime - smin;
        for(int i = 0; i < d; i++){
            if (comp > 0){
                if (comp > m.at(i).second - m.at(i).first){
                    cout << m.at(i).second << " ";
                    comp -= m.at(i).second - m.at(i).first;
                }else{
                    cout << m.at(i).first + comp << " ";
                    comp = 0;
                }
            }else cout << m.at(i).first << " ";
        }
        cout << endl;
    }
    return 0;
}